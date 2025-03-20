#include "../../minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static int bit_count = 0;
    static char character = 0;

    (void)context; // Evitar warning de variable sin usar

    if (sig == SIGUSR1)
        character |= (1 << (7 - bit_count));

    bit_count++;

    if (bit_count == 8)
    {
        write(1, &character, 1);
        if (character == '\0') // Detectar final de mensaje
            write(1, "\n", 1);
        bit_count = 0;
        character = 0;
    }

    // Enviar confirmación al cliente
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;
    pid_t pid = getpid();

    ft_printf("Servidor iniciado. PID: %d\n", pid);

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();

    return (0);
}
