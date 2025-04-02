1- Estructura y Setup Inicial
	Crear estructura del proyecto.
	Configurar Makefile
2. Parsing y Análisis de Entrada
	Leer la entrada del usuario con readline().
	Manejar la historia de comandos con add_history().
	Tokenizar la entrada (separar comandos, argumentos, operadores, etc.).
	Manejar comillas simples y dobles correctamente.
	Interpretar operadores como |, <, >, >>.
	Expandir variables de entorno ($VAR).
	Manejar * (expansión de wildcard, si lo queremos hacer).
3. Ejecución de Comandos
	Implementar fork() y execve() para ejecutar comandos externos.
	Manejar PATH para localizar comandos como ls, cat, etc.
	Implementar waitpid() y manejar procesos hijos.
	Manejar errores de ejecución (comando no encontrado, permisos, etc.).
4. Builtins (Comandos Internos)
	echo → Manejar -n y imprimir correctamente.
	cd → Cambiar de directorio y actualizar PWD.
	pwd → Imprimir el directorio actual.
	export → Añadir variables de entorno.
	unset → Eliminar variables de entorno.
	env → Mostrar variables de entorno.
	exit → Cerrar la minishell con el código de salida correcto.
5. Redirecciones y Pipes
	> → Redirección de salida (crear/truncar archivo).
	>> → Redirección de salida (append en archivo).
	< → Redirección de entrada (leer desde archivo).
	<< (heredoc) → Leer hasta encontrar una palabra clave.
	| → Conectar procesos con pipe().
6. Manejo de Señales
	Ctrl+C → No cerrar la shell, solo mostrar una nueva línea.
	Ctrl+D → Detectar EOF y cerrar la shell.
	Ctrl+\ → Ignorar o manejar adecuadamente.
7. Gestión del Entorno
	Mantener una copia del entorno al iniciar la shell.
	Permitir modificar, eliminar y añadir variables (export, unset).
	Adaptar env para mostrar el entorno.
	Manejar PWD, OLDPWD y HOME.
8. Manejo de Errores
	Mensajes de error claros (command not found, no such file or directory, etc.).
	Manejar permisos y errores en ejecución.
 9. Optimización y Testing Final
 	Pruebas con múltiples combinaciones de comandos.
	Probar en distintos entornos (bash, zsh).
	Usar valgrind para asegurar que no hay memory leaks.