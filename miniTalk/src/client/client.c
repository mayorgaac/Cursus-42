#include "../../minitalk.h"

volatile sig_atomic_t ack_received = 0;

void ack_handler(int sig)
{
    (void)sig;
    ack_received = 1;
}

void send_char(pid_t server_pid, char c)
{
  for (int i = 7; i >= 0; i--)
    {
        ack_received = 0;
        if ((c >> i) & 1)
            kill(server_pid, SIGUSR1); // Enviar bit 1
        else
            kill(server_pid, SIGUSR2); // Enviar bit 0

        while (!ack_received) // Esperar confirmación del servidor
            usleep(50); // Reducir la espera para no saturar
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        ft_printf("Uso: %s <PID del servidor> <mensaje>\n", argv[0]);
        return (1);
    }

    pid_t server_pid = ft_atoi(argv[1]);

    if(server_pid <= 0)
    {
      ft_printf("Error: PID del servidor no valido.\n");
      return (1);
    }

    char *message = argv[2];

    signal(SIGUSR1, ack_handler);

    while (*message)
        send_char(server_pid, *message++);

    // Enviar carácter nulo para indicar fin del mensaje
    send_char(server_pid, '\0');

    return (0);
}
