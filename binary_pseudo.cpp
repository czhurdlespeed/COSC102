bool binarySearch(int A[], int n,int x) {
    #include <iostream>
    int lowerBound =1;
    int upperBound = n;
    int midPoint;
    while (bool status = true) {
        if (upperBound < lowerBound) {
            cerr << x << " does not exist." << endl;
            return 1; 
        }
        midPoint = lowerBound + (upperBound-lowerBound)/2;

        if (A[midPoint] < x) {
            lowerBound = midPoint +1;
        }
        if (A[midPoint] >x) {
            upperBound = midPoint -1;
        }
        if (A[midPoint] = x) {
            cout << x << " found at location " << midPoint <<endl;
            return true;
            status = false;
        }
        
    }

}