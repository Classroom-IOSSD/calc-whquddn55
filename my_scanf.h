#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
void my_scanf(FILE* fp, const char* format, ...) {
	va_list list;
	va_start(list, format);
	while (*format) {
		if (*format == '%') {
			int value = 0;
			int tmp = 0;
			void* var;

			format++;
			switch (*format) {
			case 'd':
				while (isspace(tmp = fgetc(fp))) { }

				while (isdigit(tmp)) {
					value = value * 10 + tmp - '0';
					tmp = fgetc(fp);
				}
				ungetc(tmp, fp);

				var = va_arg(list, int*);
				*(int*)var = value;
				break;
			case 'c':
				while (isspace(value = fgetc(fp))) {}
				
				var = va_arg(list, char*);
				*(char*)var = value;
				break;
			}
			format++;
		}
		else if (*format == ' ') {
			format++;
		}
	}
}
