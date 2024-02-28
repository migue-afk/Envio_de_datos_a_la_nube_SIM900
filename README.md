Este código esta relacionado con el diseño de cirtuito que se puede obtener en la siguiente URL: https://github.com/migue-afk/sim900_schematic_power-on_operation_and_data_sending
# Envio_de_datos_a_la_nube_SIM900
Las lineas de código especifican la comunicación y envío de datos a la nube de un servidor en específico, algunas paginas web que alojan datos de forma gratuita son por ejemplo ThingSpeak, este servicio esta desarrollado para facilitar el envió de datos de un dispositivo IoT, sin embargo al momento entablar comunicación con un alojamiento de datos que encuentra localizado en servidores locales mediante el SIM900, es necesario realizar una ejecución de comandos AT de forma especifica, los requerimientos para él envió de datos dependiendo del como este constituido el servicio serán un nombre de dispositivo y la autorización que no es mas que la "contraseña" para verificar al usuario.

### Descripción de funcionamiento

Colocado la APN dependiente del proveedor del servicio de telefonía móvil y la autorización en la línea 5 y 6 respectivamente, se procede a encender el módulo SIM900 mediante software, esto no es obligatorio debido a que se puede controlar el encendido de forma manual por tanto la línea de código 18, 19, 21 se eliminaría.

La línea de código 67 dedicada a la URL que direcciona el dispositivo físico tiene la siguiente estructura https://**************/srv/rest/DATOGSM?serial=NOMBREDEL DISPOSITIVO &dato=1&bateria=5&memoria=5

 *Se recomienda antes de emplear el código en un microcontrolador realizar las pruebas de comunicación y requerimientos mediante software dedicado como  Postman o SoapUI.*

*Además verificar la comunicación entre el monitor serial y el SIM900, para el caso es de 19200 baudios*
