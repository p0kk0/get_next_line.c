char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp_buffer;
	ssize_t		read_bytes;

	buffer = NULL;
	read_bytes = 1; //Decimos que es 1, para que entre dentro del bucle.
	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	while (read_bytes > 0) //Cuando los bytes leídos sean 0, habremos acabado.
	{
		temp_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!temp_buffer)
			return (0);
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, temp_buffer);
		printf("Bytes read: %zd\n", read_bytes);
		printf("El buffer contiene: %s\n", buffer);
		printf("El temp_buffer contiene: %s\n", temp_buffer);
	}
	printf("El buffer contiene: %s\n", buffer);
	return (temp_buffer);
}
