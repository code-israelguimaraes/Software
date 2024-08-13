int arduinoIO;
int number;

int cgui_arduinoinit(const char *IDserial) {
    // Abrir a porta serial
    static int serial_port = -1;
    if (serial_port == -1) {
        
        serial_port = open(IDserial, O_RDWR | O_NOCTTY | O_SYNC);
        
        // Configurar a porta serial
        struct termios tty;
        if (tcgetattr(serial_port, &tty) != 0) {
            perror("Error from tcgetattr");
            close(serial_port);
            serial_port = -1;
            return 1;
        }

        // Configurar a taxa de transmissão
        cfsetospeed(&tty, B9600);
        cfsetispeed(&tty, B9600);

        // Configurar os parâmetros da porta
        tty.c_cflag |= (CLOCAL | CREAD); // Habilita leitura e ignora o controle de linha
        tty.c_cflag &= ~PARENB; // Desativa a paridade
        tty.c_cflag &= ~CSTOPB; // Usa 1 bit de parada
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8; // Define 8 bits de dados

        // Configurar o controle de fluxo e processamento de saída
        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Desativa controle de fluxo por software
        tty.c_iflag &= ~(ICRNL); // Não converte retornos de carro em nova linha
        tty.c_oflag &= ~OPOST; // Desativa o processamento de saída

        // Aplica as configurações
        tcsetattr(serial_port, TCSANOW, &tty);
    }
    
	 // Limpa o buffer de recepção
    tcflush(serial_port,TCIFLUSH);

    // Buffer para leitura
    char read_buf[256];
    int num_bytes = read(serial_port, read_buf, sizeof(read_buf) - 1);

    if (num_bytes < 0) {
        perror("Error reading from serial port");
        return 1;
    } else if (num_bytes > 0) {
        read_buf[num_bytes] = '\0'; // Adiciona o terminador de string
        
        // Converte a string recebida para um número inteiro
        number = atoi(read_buf); // `atoi` converte a string para um inteiro
        
        // Exibe o número lido (opcional)
        //printf("Número lido: %d\n", number);
    }

    return number;
}
