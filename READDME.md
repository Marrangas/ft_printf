# ft_prinf
typedef struct {
   unsigned int gp_offset;
   unsigned int fp_offset;
   void *overflow_arg_area;
   void *reg_save_area;
} va_list[1];


.  (cómo es la librería que estoy tratabdo de utilizar)
va_start establece arg_ptr en el primer argumento opcional de la lista de argumentos que se pasa a la función. El argumento arg_ptr debe tener el tipo va_list. El argumento prev_param es el nombre del parámetro necesario inmediatamente anterior al primer argumento opcional de la lista de argumentos. Si prev_param se declara con la clase de almacenamiento de registro, el comportamiento de la macro es indefinido. Es necesario usar va_start antes de usar va_arg por primera vez.

va_arg recupera un valor de type de la ubicación determinada por arg_ptr, y aumenta arg_ptr para señalar al argumento siguiente de la lista usando el tamaño de type para determinar donde empieza el argumento siguiente. va_arg se puede usar un número ilimitado de veces en la función para recuperar argumentos de la lista.

va_copy realiza una copia de una lista de argumentos en su estado actual. El parámetro de src debe estar ya inicializado con va_start; puede haberse actualizado con llamadas de va_arg, pero no puede haberse restablecido con va_end. El siguiente argumento recuperado por va_arg de dest es el mismo que el siguiente argumento se recupera de src.

Una vez recuperados todos los argumentos, va_end restablece el puntero a NULL. Es necesario llamar a va_end en cada lista de argumentos que se inicialice con va_start o va_copy antes de que la función devuelva su resultado.
}
no hace falta buffer manadgement

Tipos de variables:
c sigle char
s sstring (según convenciones de C)
p void * en formato hexadecimal
d decimal (base 10)
i integer en bas 10
u unsigned decimal base 10
x hexadecimal en lowercase
X hexadecimal en uppercase
%% printea un signo de porcentaje

comando ar para crear la lib (noo se puede crear la llibtool)

libftprintf.a debe crearse en la raiz del repo

BONUS?
flags:
- 
et nornu
Justifica el campo a la izquierda (por defecto ya hemos dicho que se justifica a la derecha)
O 
	Se rellena con ceros a la izquierda hasta el valor dado por el flag anterior. Por ejemplo “%03d” imprime un número justificado con ceros hasta tres dígitos.
.
	número a utilizar se pasa como parámetro justo antes del valor. Por ejemplo printf("%.*s", 3, "abcdef") imprime “abc”

flag
# 
	Prefix 0 to the output value when used with the octal conversion character o
	Formato alternativo. Para reales se dejan ceros al final y se imprime siempre la coma. Para números que no están en base 10, se añade un prefijo denotando la bas
' ' 
	(el espaio) Print a space before a positive value not printed with the + flag
+
	Imprimir el signo de un número
	Display a plus sign preceding positive values and a minus sign preceding negative values.

*/


## Tester
[Paulo Santana - Tester](https://github.com/paulo-santana/ft_printf_tester)                     <br/>
[Tripouille    - Tester](https://github.com/Tripouille/printfTester)                            <br/>
[Mazoise       - Tester](https://github.com/Mazoise/42TESTERS-PRINTF/tree/master/srcs)          <br/>
[]()

## Referencias
[Formatos va_list](https://stackoverflow.com/questions/4958384/what-is-the-format-of-the-x86-64-va-list-structure#:~:text=The%20va_list%20type%20is%20an,is%20given%20in%20%EF%AC%81gure%203.34)        <br/>

