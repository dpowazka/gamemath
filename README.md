gamemath
========

Few usfull game math classes. 

Complex
--------
Functionally it is simular to std::complex but there are few differnces.
Game Math Complex class is intetned for use in 2D games as position or some kind of vector(egz. velocity) to support that it uses .x and .y rather then .re and .im, which are public so rendering calls would be as fast as they can.
