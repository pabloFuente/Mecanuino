
# Mecanuino

### 1. Introducción

Este proyecto trata sobre un coche radiocontrol que hace uso de ruedas de tipo *Mecanum*, las cuales permiten una libertad de movimiento mucho mayor que las de un coche normal, en varios ejes distintos, tal y como se detallará más adelante.

**Rueda mecánica**

<img  class="logo" src="http://www.makeblock.com/image/cache/catalog/95067/95067-2-800x800.png" width="300">

El coche será controlado desde una app en Android que envía mediante bluetooth los movimientos que queremos realizar.

### 2. Materiales

![Materiales](https://lh3.googleusercontent.com/-0KVZjUAu2Wc/WP-fmjPJwRI/AAAAAAAAA2I/PUtuBm_i_FAs9hYaGKA5-ih0G6SIksAGQCLcB/s0/photo_2017-04-25_21-12-14.jpg "photo_2017-04-25_21-12-14.jpg")

Componente | Unidades | Precio x Unidad | Precio final
-- | --  | --  | -- 
Mecanum Wheels | 4 | 19,25 € | 77 €
4mm Aluminum Mounting Hub for 60mm Mecanum Wheel |4| 10 € | 30 €
TB6612FNG Dual Motor Driver Carrier | 2 | 5 € | 10 €
DC motor 12V | 4 | 5€ | 20€
HC-06 bluetooth module or similar | 1 | 6€ |6€
Arduino Mega 2560 | 1 | 10 € |	10€
Breadboard | 1 | 2€ | 2€
Li-Po battery 7.4V 1800 mAh | 1 | 11 € | 11 €
Li-Po battery 11.1V 3000 mAh | 1 | 23 €| 23 €
SKYRC iMAX B6 Mini battery charger | 1 | 37€ | 37€
Chassis | 1 | Reciclado | 0 €
Cables	| 1 | 1€ | 1 €
Total  | - | - | **216 €**

### 3. Esquema de conexiones

![Conexiones](https://lh3.googleusercontent.com/-H1CBM3AJRrQ/WP-QUuoVhXI/AAAAAAAAA0A/XN4X4WRri5g-1dt7fb1Lwhvh0wRSZHByACLcB/s0/photo_2017-04-25_20-07-02.jpg "photo_2017-04-25_20-07-02.jpg")

El cerebro Arduino del proyecto es una Mega 2560. En cuanto al resto de componentes electrónicos, destacan el módulo Bluetooth HC-06 (que solo puede actuar de esclavo) y los dos Dual Motor Driver Carriers.
Estos componentes permiten controlar dos motores de corriente directa de entre 4,5 y 13,5 voltios, regulando tanto su velocidad como su dirección.

### 4. Montaje

-	**Fase 1: Circuito**
En primer lugar, comenzamos a realizar todas las conexiones de la placa de arduino con el módulo Bluetooth y los controladores de los motores, tal y como se muestra en el esquema de conexiones.

 ![Fase1-Circuito](https://lh3.googleusercontent.com/-BYnhT-oe_zA/WP-VeMscq7I/AAAAAAAAA0k/3RJ2-1CFYQQ6u7imdCcjcAPUjOxK3-l0ACLcB/s0/photo_2017-04-24_23-31-49.jpg)

 ![Fase1-Soldadura](https://lh3.googleusercontent.com/-TicIkAuZfHA/WP-UQ4ZtjMI/AAAAAAAAA0Q/7MNYsYrMx5s97BexRDr251yFQXqexAQdACLcB/s0/photo_2017-04-25_20-23-35.jpg)

 
- **Fase 2: Conexión con los motores**
Tras tener listo el circuito anterior, pasamos a la conexión con los motores, además de añadir al circuito la batería necesaria para alimentarlos.

 ![Fase2](https://lh3.googleusercontent.com/--Qq15N-4DFs/WP-XRnS-2ZI/AAAAAAAAA00/jy8rBb0HT_Y8JM4Sa5TlwMuWb8pwld-wgCLcB/s0/photo_2017-04-24_23-38-02.jpg "photo_2017-04-24_23-38-02.jpg")

 Al tener 4 motores independientes, y para asegurar el correcto funcionamiento de los mismo con los movimientos mencionados, hicimos una prueba con ruedas de cartón, donde probábamos además la conexión App de Android -> Módulo Bluetooth -> Arduino -> Motores
 
 [Demo Beta](https://www.youtube.com/embed/738GMchX6sQ)

- **Fase 3: Conexión rueda-motor**
Una vez comprobamos que el funcionamiento de los motores, sustituimos las ruedas de cartón por las ruedas mecánicas: 

 ![Fase 3 - Rueda ](https://lh3.googleusercontent.com/-V2zhqE0mquw/WP-eTvpgfXI/AAAAAAAAA14/rTk9TnG4wrYMSL3RduxysuVETk3DMRzGACLcB/s0/photo_2017-04-24_23-31-17.jpg "photo_2017-04-24_23-31-17.jpg")

 #### Resultado final: 
 ![Coche 1](https://lh3.googleusercontent.com/-c8NH4fNWve0/WP-jwErSnvI/AAAAAAAAA2c/Al0ye0PR6zQnNxHUb5_ACmepcQIrEGU7gCLcB/s0/photo_2017-04-25_21-29-29.jpg)
  
 ![Coche 2](https://lh3.googleusercontent.com/5aZgV02F_2x-YBYMmtEENXnXTVz933mH_hcoYdwQaHwVsWFkolVCtk2RBatXWEl6W-IGKJ4y=s0)

### 5. Funcionamiento

#### Funcionamiento físico
La física detrás de este coche se basa en operaciones de suma de fuerzas vectoriales muy sencillas. Para los movimientos permitidos se adjuntan a continuación un diagrama en el que se exponen dichas fuerzas:

##### Hacia delante
![Forward](https://docs.google.com/uc?id=0B61cQ4sbhmWSUlNOVUNnTzRLRmc)

##### Hacia atrás
![Backwards](https://docs.google.com/uc?id=0B61cQ4sbhmWSSnlSdDg2dkN3Slk)

##### Hacia la izquierda
![Left](https://docs.google.com/uc?id=0B61cQ4sbhmWSWWVCZU84QlJCems)

##### Hacia la derecha
![Right](https://docs.google.com/uc?id=0B61cQ4sbhmWSNmlSN2lsRnIxeFE)

##### Diagonal adelante izquierda
![Right](https://docs.google.com/uc?id=0B61cQ4sbhmWSUmRPZXNIMi02U1E)

##### Diagonal adelante derecha
![Right](https://docs.google.com/uc?id=0B61cQ4sbhmWSTnhJbEFmdnlWLTg)

##### Diagonal atrás izquierda
![Right](https://docs.google.com/uc?id=0B61cQ4sbhmWSU2wwamQ1YkJDTUk)

##### Diagonal atrás derecha
![Right](https://docs.google.com/uc?id=0B61cQ4sbhmWSRTYyVV9MT3BNSUE)

#### Funcionamiento software
La parte de Arduino se encarga de escuchar el Serial1, que corresponde a la conexión bluetooth.

```c
void loop(){
  // SOLO SI BLUETOOTH DISPONIBLE...
  if (Serial1.available()) {
    leerTecla();
  }
}
```

La app en Android se encarga de enviar el movimiento que elije el usuario a través del módulo bluetooth:

<img src="https://lh3.googleusercontent.com/-6D-b01Y6e2o/WP_Ff2dbReI/AAAAAAAAA3Q/ChOICpLKSeQzlRa5sV0fHbiApCFmaAUSgCLcB/s0/photo_2017-04-25_17-23-22.jpg" width="300" />

Arduino se encarga de leer la información que le llega al módulo, que para simplificarlo, será únicamente un caracter. Para un movimiento diagonal, arriba a la derecha, el código (simplificado) sería:

```c
void leerTecla (){
  // <code>
  byte character = Serial1.read();
  // <code>
  case 'c': // Delante derecha
    delanteDerecha(VELOCITY);
    break; 
}
```
Este movimiento requerirá el uso de dos motores (delante izquierda y atrás derecha), dejando los otros dos inactivos (velocidad = 0)
```c
void delanteDerecha(int velocidad){
  Serial.print("Delante derecha!");
  controlMotor("del_der", 1, 0);
  controlMotor("del_izq", 1, velocidad);
  controlMotor("atr_der", 1, velocidad);
  controlMotor("atr_izq", 1, 0);
}

void controlMotor(String motorStr,int mdirection, int velocidad){
  int IN1;
  int IN2;
  int motorPWM;
  if (motorStr == "del_der") { // Motor delante derecha
    IN1 = AIN1_DelanteDerecha; 
    IN2 = AIN2_DelanteDerecha;
    motorPWM = PWM_DelanteDerecha;
  }   
  else if (motorStr == "del_izq") { // Motor delante izquierda
    IN1 = BIN1_DelanteIzquierda; 
    IN2 = BIN2_DelanteIzquierda;
    motorPWM = PWM_DelanteIzquierda;
  }
  else if (motorStr == "atr_der") { // Motor atrás derecha
    IN1 = AIN1_AtrasDerecha; 
    IN2 = AIN2_AtrasDerecha;
    motorPWM = PWM_AtrasDerecha;
  }
  else if (motorStr == "atr_izq") { // Motor atrás izquierda
    IN1 = BIN1_AtrasIzquierda; 
    IN2 = BIN2_AtrasIzquierda;
    motorPWM = PWM_AtrasIzquierda;
  }
  if (mdirection == 1){
    Serial.print("Hacia delante");
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH); 
  }
  else if (mdirection == -1){
    Serial.print("Hacia atrás");
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
  }
  analogWrite(motorPWM, velocidad);
}
```
#### Demo

**Nota:** El coche se encuentra suspendido para evitar la fricción de las ruedas con el suelo a fin de poder apreciar los giros de las mismas.

[Demo](https://www.youtube.com/embed/cBFNSqZjjm0)

### 6. Problemas y soluciones

Entre los primeros problemas que nos encontramos estaba **la soldadura de los pines de los controladores** al breadboard. Con que una de las conexiones no estuviese correctamente realizada, no se producía respuesta por parte del controlodar. Mediante el uso de un voltímetro y tras realizar lo que podría llegar a llamarse microsoldadura varias veces, conseguimos que funcionaran todas las conexiones.

El mayor problema que nos encontramos y al que no hemos podido dar solución es **la conexión de las ruedas y los motores**. Las ruedas resultaron demasiado grandes y sobre todo demasiado pesadas para los motores, por lo que al poner en coche en el suelo, los motores no tenían suficiente par para desplazar el vehículo. Para este problema había dos soluciones: usar motores mas potentes (y la consiguiente batería) o utilizar ruedas más pequeñas (de 60mm). En cualquier caso, ambas soluciones y dado el presupuesto del proyecto (y las fechas de envío, unos 60 días) nos imposibilitaron hallar una solución a tiempo.


### 7. Posibles mejoras

Resueltos los problemas mencionados, entre las posibles mejoras podemos destacar:

- Mejora del chasis, tanto a nivel estetico como estructural
- Explorar nuevos movimientos (rotación sobre si mismo)
- Adición de memoria de rutas
- Integración de una webcam para control remoto

### 8. Anexos

[Repositorio de GitHub dónde se encuentra el código](https://github.com/pabloFuente/Mecanuino)

[App de Android para el control del vehículo](https://play.google.com/store/apps/details?id=pl.mobilerobots.vacuumcleanerrobot&hl=en)

[Presentación del proyecto en Prezi](http://prezi.com/6lnkmxu3lvlz/?utm_campaign=share&utm_medium=copy&rc=ex0share)
