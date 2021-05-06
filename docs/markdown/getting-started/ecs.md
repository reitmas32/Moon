### **ECS(Entity Component System)**

La manipulación de los datos de un vídeo juego es una tarea compleja de administrar cuando uno esta iniciando en el desarrollo de vídeo juegos, podrías terminar con un acoplamiento entre las partes que lo componen a tal punto en el que el modulo encargado de la física también manipule datos de renderizado. Por esta razón es importante tener una buena planificación.

La arquitectura ECS "Entity Component System" es una forma sencilla y eficiente de administrar los recursos de un vídeo juego, como su nombre lo indica esta se basa en separa los Datos "Entity Component" de la manipulación e interpretación de los mismos "System"