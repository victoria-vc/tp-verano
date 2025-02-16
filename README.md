# tp-verano

Trabajo práctico promoción Curso de verano 2025  
Modalidad:  
Se deberá realizar el desarrollo del trabajo con fecha de entrega el día 20 de FEBRERO
para aquellos que promocionen, los que no estén en condiciones de promocionar pueden
entregar hasta el cierre de la materia el 2 de marzo.  
Lineamientos de entrega:  

• Carátula con todos los integrantes  
• Archivo con el código (cpp)  
• Ejecutable  
• Documento con un detalle de como se resolvió el problema, manual de
usuario y pantallas que muestren que el programa funciona
• Archivos anexos: se deben incluir los archivos que se utilicen en las
pruebas  
• Máximo 5 integrantes  
• No pueden usar bibliotecas externas , solo lo aprendido en clase
• Caso de copia: desaprueban la materia.  
• El trabajo para darse por cumplido debe entregarse funcionando con todos
los ítems desarrollados.  
• Se entrega por campus una copia por grupo.  

Una fábrica de zapatos requiere calcular cuantos accesorios debe comprar en función de
la producción que debe realizar. Para eso tiene un maestro que indica según el modelo a
fabricar la cantidad y tipo de accesorio.  
Se cuenta con los siguientes datos:  
Vector de modelos(50):  
• Id de modelo (número secuencial)  
• descripción (cadena de 100 caracteres)  
• Precio base  
• Temporada (verano – invierno)  
• Ptr a la lista de componentes:  
o Id accesorio  
o cantidad  
Vector de componentes (1000)  
• Id (secuencia completa que comienza en 1000)  
• descripción (cadena de 100 caracteres)  
• lista de proveedores  
• stock  
Lista de proveedores tiene los siguientes datos:  
• id (numérico sin secuencia)  
• nombre  
• valor unitario  

Archivo de pedidos:  
• id de pedido  
• id de linea  
• fecha  
• id de modelo  
• cantidad  
• costo  
  
Se solicita:  
Dado un archivo de pedidos se requiere calcular el costo parcial de cada línea de pedido,
actualizando el archivo, el stock de componentes y mostrando el costo total del mismo.
Se debe considerar que se tiene que tomar el menor valor para cada componente dada la
lista de proveedores de cada uno.  
La salida del sistema deberá mostrar el archivo de pedidos con los costos actualizados y
el costo total.  

