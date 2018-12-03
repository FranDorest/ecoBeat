# Objetivo

En este documento se indica como cargar correctamente el Firmware al ATtiny 85 para el equipo ecoBeat.

El microcontrolador ATtiny 85 se encarga de contabilizar los impulsos emitidos por la sonda óptica de Open Energy Monitor y transmitirlos mediante comunicación serie al ESP8266. Esta medida de impulsos se utilizará en el servidor Open Energy Monitor para calcular el consumo de energía total y la potencia instantánea de su instalación.

## HERRAMIENTAS Y COMPONENTES
Para poder cargar el firmware a un ATtiny85, necesitará los siguientes componentes:

 - Arduino UNO 
 -  ATtiny85 
 - Placa de prototipado
 - Condensador electrolítico 10uF/25v
 - Cables dupont macho macho
 - Cable USB

> **Nota:** Podrá adquirir los componentes necesarios en la mayoría de tiendas físicas de componentes electrónicos o en internet.


## CONFIGURAR ARDUINO

Para utilizar el Arduino UNO como un programador de microcontroladores Atmel necesitamos configurarlo como un programador ISP (in-system-programming). Para ello el IDE de Arduino nos facilita el código que hace esto posible y se encuentra dentro de la carpeta de ejemplos bajo el nombre de **ArduinoISP. File -> Examples -> ArduinoISP**. 

Una vez abierto el ejemplo conectamos el Arduino uno al ordenador mediante el cable usb, seleccionamos en el Arduino IDE el tipo de placa correcta (Arduino/Genuino UNO) y el puerto serie correspondiente y cargamos el sketch.

> **Nota:** El nombre del Puerto serie dependerá del SO que use, pudiendo ser COMX en Windows o /tty/USBX en sistemas operativos en base Linux.


## SOPORTE ATTINY

Arduino IDE no soporta el microcontrolador ATtiny85 por defecto, así que debemos añadirlo manualmente. Para ello accedemos a las preferencias de **Arduino IDE en File -> preferences** y añadimos la siguiente URL a **Additional Boards Manager URLs..**

    https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boardsmanager/package_damellis_attiny_index.json

Después de aceptar la nueva configuración debemos añadir el controlador a la librería de placas. Para ello
accedemos a **Tools -> Board -> Boards Manager…** y buscamos el paquete **“attiny by Davis A. Mellis”**. Lo seleccionamos e instalamos.
Después de esto debería ser capaz de encontrar dentro de **Tools -> Board** una opción llamada **Attiny**, que nos indica que la instalación se ha completado correctamente. Puede añadir más URLs de otras librerías separando las direcciones con comas.

## CONECTAR ARDUINO Y ATTINY
Una vez se haya completado la configuración anterior podemos conectar el ATtiny85 al Arduino UNO para empezar a programarlo. Para ello debemos montar el siguiente circuito teniendo en cuenta la posición del ATtiny.

| Arduino UNO | ATtiny85 |
|--|--|
| 5v | PIN 5 |
| GND | PIN4 |
| PIN 13 | PIN 6 |
| PIN 12 | PIN 7 |
| PIN 11 | PIN 8 |
| PIN 10 | PIN 1 |

> **Nota:** Añadiendo un condensador electrolítico de 10uF entre RESET y GND en el Arduino UNO evita que se produzca un RESET mientras cargamos el Firmware al ATtiny85.

>**Nota:** -Un circulo sobre el microcontrolador marca la posición del pin 1.

## CARGAR EL CÓDIGO AL ATTINY

Volviendo al Arduino IDE, seleccionamos en **Tools -> Board** la opción ATtiny25/45/85, en **Tools -> Processor** la opción ATtiny85, en **Tools -> Clock** Internal 8mHz, el puerto serie correspondiente y clicamos en **Burn Bootloader** . Si la carga se ha realizado correctamente podremos ver en la parte inferior del IDE **Done burning bootloader**. (La carga del bootloader no debe tardar más de 1 minuto). Una vez cargado podemos abrir la última versión del Firmware para el equipo ecoBeat bajo el nombre de **Firmware_ATtiny85_x.h** en la carpeta del proyecto y cargarlo normalmente con la misma configuración que usamos antes.

>**Nota:** Si observa falsas lecturas en el equipo puede incrementar el tiempo entre lecturas aumentando el valor de la constante **DEBOUNCE** en el código.
>
## COMPROBAR LA CARGA

Para asegurarnos de que todo el proceso ha sido realizado correctamente podemos montar el ATtiny85 ya
programado en el zócalo de 8 pines de la placa terminada del equipo ecoBeat y conectarle la sonda óptica de Open Energy monitor. Una vez montado debemos conectar el equipo a la fuente de alimentación y apuntar la sonda a una fuente de luz tenue. Al pasar la mano repetidas veces sobre la sonda deberíamos poder ver el led imp del equipo parpadear, confirmando que se ha realizado la carga con éxito.

>**Nota:** Si el led imp del equipo no parpadea debemos repetir las instrucciones desde el punto 5. Si esto no soluciona el problema póngase en contacto con nosotros.
