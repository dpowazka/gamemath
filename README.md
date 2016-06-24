gamemath
========

Few usfull game math classes. 

Complex
--------
Functionally it is simular to std::complex but there are few differnces.
Game Math Complex class is intetned for use in 2D games as position or some kind of vector(egz. velocity) to support that it uses .x and .y rather then .re and .im, which are public so rendering calls would be as fast as they can. Complex has only explict contructors
so Complex<float>(1.0f, 1.0f) + 1.0f will fail to compile, as it is likaly an mistake - use some_complex_var.x + 1.0f insted. But it overloads operator*, so typical operation Complex<float> velocity(1, 1); float dt = 0.02f; position += dt*velocity; will work just fine.

Vector2 
--------
Represents 2D vector and it's typical operations +,-,*, rotations and normalization. Vector2 has no operator +,- for float/int/double be desing 
so the operataions always are on vectors. 

Matrix
--------
