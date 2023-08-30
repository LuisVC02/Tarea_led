#include <stdio.h>

int main()
{
	int option = 0;
	while(option != 4)
	{
		char value = 0;
		FILE *ptr;
		FILE *ptr_read;
		printf("Ingrese una opcion para el led\n1 -> Enciende\n2-> Apaga\n3 -> Random\n4 -> Cerrar\n");
		scanf("%i", &option);
		ptr = fopen("/sys/class/leds/gpio-led//brightness", "w");
		ptr_read = fopen("/cat/dev/random", "rb");
		if(1 == option)
		{
			fprintf(ptr, "%i", 1);
			printf("Encendido\n");
		}
		else if(2 == option)
		{
			fprintf(ptr, "%i", 0);
			printf("Apagado\n");
		}
		else if(3 == option)
		{
			value = fread(&value, sizeof(char), 1, ptr_read);
			if(value > 128)
			{
				fprintf(ptr, "%i", 1);
			}
			else
			{
				fprintf(ptr, "%i", 0);
			}
			printf("Random = %d\n", value);
		}
		else if(4 == option)
		{
			printf("Hasta luego\n");
		}
		else
		{
			printf("Opcion incorrecta\n");
		}
		fclose(ptr);
		fclose(ptr_read);
	}
	return 0;
}
