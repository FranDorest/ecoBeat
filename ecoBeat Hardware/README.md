# PCB ecoBeat 3

Se ha creado una nueva PCB que se adapta a las medidas de una caja de montaje en carril DIN.


### Materiales

A continuación aparecen los materiales que se necesitarán para construir la placa *ecoBeat*.

* [Soldador] 
* [Estaño]
* [Pinzas]
* [ESP 12 F](https://www.elecrow.com/download/ESP-12F.pdf) - Microcontrolador de 32-bit 
* [ATtiny 85](http://www.farnell.com/datasheets/1698186.pdf) - Microcontrolador de 8-bit
* [LM1117 3.3v](http://www.ti.com/lit/ds/symlink/lm1117.pdf) - Regulador de voltaje 15v - 3.3v 800mA
* [RJ45 8P8P Female](https://es.rs-online.com/web/p/conectores-rj45/2578814/) - Conector RJ45
* [2x Pulsador](https://www.adafruit.com/product/367) - Pulsador 6x6mm
* [4x 10k R](https://es.rs-online.com/web/p/resistencias-fijas-de-orificio-pasante/7077745/) - Resistencia 10k 1/4W
* [3x 220 R](https://es.rs-online.com/web/p/resistencias-fijas-de-orificio-pasante/7077612/) - Resistencia 220 1/4W
* [1x 12k R](https://es.rs-online.com/web/p/resistencias-fijas-de-orificio-pasante/7077735/) - Resistencia 12k 1/4W
* [1x 6.8k R](https://es.rs-online.com/web/p/resistencias-fijas-de-orificio-pasante/7077735/) - Resistencia 6.8k 1/4W
* [2x 10uF C](https://es.rs-online.com/web/p/condensadores-de-aluminio/0117035/) - Condensador electrolítico 10uF 50v
* [1x 100nF C](https://es.rs-online.com/web/p/condensadores-ceramicos-multicapa/5373707/) - Condensador cerámico 100nF 50v
* [1x Diodo](https://es.rs-online.com/web/p/products/7965985/?tpr=1) - Diodo 1A
* [3x LED](https://es.rs-online.com/web/p/led-visibles/2285944/) - LED 3mm
* [Pin macho 2.54mm](https://es.rs-online.com/web/p/conectores-macho-para-pcb/5473166/) - Tira pin Macho 2.54mm
* [Pin macho 2mm](https://es.rs-online.com/web/p/conectores-macho-para-pcb/6813293/) - Tira pin Macho 2mm
* [Pin hembra 2mm](https://es.rs-online.com/web/p/conectores-hembra-para-pcb/6058774/) - Tira pin hembra 2mm


### Montaje

*


## Herramientas

* [KiCad 4.0.2](http://kicad-pcb.org/) - Diseño electrónico

## Consumos

*Se ha realizado una prueba para conocer los consumos del equipo en todas sus modos de trabajo en su versión de 5V.

                      Con LEDs          Sin LEDs

*AP ->                87 - 88           85-86         mA 

*STA + AP ->          87 - 88           85 - 86       mA

* STA ->              85.5 - 86.5       83.5 - 84.5   mA

*Envío de datos ->    86.5 - 87.5       84.5 - 85.5   mA

*Vmax 12V. El regulador se calentará hasta los 65ºC y consumirá 84,5mA.


## Autores

* **Francisco Doreste** 
* **Oscar Pujal** 


## Licencia

Este proyecto se encuentra bajo licencia GPL.



