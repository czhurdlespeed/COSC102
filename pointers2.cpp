/* Suppose I have the following declarations 
int a, b, c;
int *p, *q, *r;
Also suppose the following vars are assigned to the following mem addresses:
a: 0x1000           p: 0x100c
b: 0x1004           q: 0x1010
c: 0x1008           r: 0x1014

p = &c;
*p = 20;
p = &a;
*p = 40;
q = p;
b = *q + *p;
cout << a << " "<< b << c << p << q << endl;

    0x1000                  0x1000c
a:    40                 p:  0x1000

    0x1004                  0x1010
b:    80                 q:  0x1000

    0x1008                  0x1014
c:    20                 r:     


a= 60;
b = 20;
c= 70;
r = &b;
b = a +c;
p = new int;
*p = 2;
q = new int;
*q = a/*p;
print:
a:  60        *p: 2
b:   130      *q: 30
c:   70       *r: 130
            
_____________________

ptr.arr = new int[5] ----> create 4 integers (cons) and returns a ptr to the 1st one

ptr.arr 0x1000

ptr.arr[0] would be @ 0x1000
ptr.arr[1] @ 0x1004
ptr.arr[2] @ 0x1008
ptr.arr[2] =10;
*(ptr.arr+2) = 10; (ptr arithmetic)  ptr.arr[2] @ 0x1008

brackets [] automatically dereference
we can us them to trat a ptr like an array

adding/subtracting from a ptr
walks us to the next data type of the ptr in contiguous memory
ex. *(ptr.arr +2) = 10;
this is analogous to moving to the next element in the array  +2 = 8 bytes for integer datatype; +2 = 16 bytes for double datatype
ex. int *a = (int*) 0x64; //100 in hex
cout << (a+10);  
result = 100 + (10*4) = 140 = 0x8c


int array[] = {1, 2, 3, 4, 5};
int *ptr.a = array +1; (Result: 2)
cout <<*(ptr.a + 1);
result: 2
            */
    
