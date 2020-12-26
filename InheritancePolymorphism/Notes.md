# Inheritance

<h2><u><b>Book Notes</b></u></h2>

<h4>Inheritance</h4>
<ul>
	<li>
        Inheritance allows a new class to be based on an existing class.
        The new class automatically inherits all the member variables and functions, exceot
        the contructor and destructor, of the class it is based on.
    </li>
	<li>
        Inheritance is an "Is a" relationship
    </li>
    <li>
        <i>Example: </i> class Final Exam : public Graded Activity
        </br> <i> : = base class access specification</i>
        It affects how the members of the base class are inherited by the derived class.
    </li>
	<li>
        <b><i>Protected members</i></b> of a base class are like private members, but they may be accessed
        by dreived classes. 
    </li>
    <li>
        When a derived class member function has the same name as a base class member function, it is said the
        derived class function <i>redefines</i> trh base class function. When an object of the derived class calls
        the fucntion, it calls the derived class's version of the function.
    </li>
    <li>
        <i>Overloading</i> a function is a function with the same name but different parameters.
    </li>
</ul>

<h4>Polymorphism</h4>
<ul>
	<li>
        Polymorphism allows an object reference variable or an object pointer to reference objects of different types
        and call the correct member function, depending upon the type of object being referenced. 
    </li>
    <li>
        <i>Binding</i> - How C++ matches functions call to the correct function.
    </li>
    <li>
        The process of matching a function call with the function at complie time is called static binding.
    </li>
    <li>
        In order to fix the issue so that the function calls the correct function, we can use <i>virtual functions</i>.
        A virtual function is a member function that is dynamically bound to a function call. In <i>Dynamic Binding</i>, C++
        determines which function to call at runtime, depending on the type of object resposible for the call.
    </li>
    <li>
        <b>Example: </b> <i>virtual char getLetterGrade() const;</i>
    </li>
    <li>
        Pylomorphism requires references or pointers.
    </li>
    <li>
        <b>IMPORTANT</b>
        </br>
        When a class redifines a virtual function, it is sauid that the class overrrides the function. The difference between redefinig 
        base class functions is that overridden functions are dynamically bound, and redefined functions are statically bound. Only 
        virtual functions can be overriden.
    </li>
</ul>
