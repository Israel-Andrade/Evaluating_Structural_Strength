//Emily Garcia, Steven Groves, Israel Andrade
//Date: 10/30/2015
//Description: Read the files into two seprate arrays, called steel and graphite. Assume that these arrays may need to hold 20 values. They will be partially filled arrays. Write the functions Mean, Maximum Value, Minimum Value, Variance, Standard Deviation to take these arrays and calculate the following statistical values
#include <cmath> 
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double mean(vector<int> v);
// Summary: Obatin the sum of all elements in the vector and divided by the size of that vector
// Precondition: vector will be implemented with correct corresponding values
// Postcondition: Mean function will return a double. This double will be the mean of each vector being passed in

int maxValue(vector<int> v);
// Summary: determines the max value in a given vector
// Precondition: takes a vector
// Postcondition: returns the largest value in the vector

int minValue(vector<int> v);
// Summary: determines the min value in a given vector
// Precondition: takes a vector
// Postcondition: returns the smallest value in the vector

double variance(vector<int> v);
// Summary: Determines the variance value in a given vector.
// Precondition: Takes in a vector.
// Postcondition: Returns the variance value in the vector.
double standardDeviation(double var);
// Summary: Determines the standard deviation value in a given vector.
// Precondition: Takes in a vector.
// Postcondition: Returns the standard deviation value in the vector
int main()
{
    ifstream steelStream, graphiteStream;
    steelStream.open("data1.txt");
    graphiteStream.open("data2.txt");
    int valueForSteel, valueForGraphite;
    vector<int> steel;
    vector<int> graphite;
    
    while(steelStream >> valueForSteel)
    {
        steel.push_back(valueForSteel);        
    }
    while(graphiteStream >> valueForGraphite)
    {
        graphite.push_back(valueForGraphite);        
    }
    
    double meanOfSteal = mean(steel);
    
    cout << setw(30) << "Steel File " << setw(30) << "Graphite File" << endl;
    cout << "Mean" << setw(22) << mean(steel) << setw(28) << mean(graphite) << endl;
    cout << "Maximum" << setw(17) << maxValue(steel) << setw(28) << maxValue(graphite) << endl;
    cout << "Minimum" << setw(17) << minValue(steel) << setw(28) << minValue(graphite) << endl;
    cout << "Variance" << setw(17) <<  variance(steel) << setw(28) <<  variance(graphite) << endl;  
    cout << "Standard Deviation" << setw(8) << standardDeviation(variance(steel)) << setw(28) << standardDeviation(variance(graphite)) << endl; 
    
    //Formmula to determine if the coupon  
    double couponEligibleSteel =  (standardDeviation(variance(steel)) * 3) - (mean(steel));
    double couponEligbleGraphite = (standardDeviation(variance(graphite)) * 3) - (mean(graphite));
    if(couponEligibleSteel > 16000)
    {
        cout << "Steel is eligible" << endl;
    }
    else
    {
        cout << "Steel is not eligible" << endl;
    }
    if(couponEligbleGraphite > 16000)
    {
        cout << "Graphite is eligilble" << endl;
    }
    else
    {
        cout << "Graphite is not eligilble" << endl;
    }
    
    
    /*
The coupons for both steel and graphite values failed to meet the standards of eligibility. The standards for both values had been calculated by obtaining the standard deviation of both steel and graphite. After obtaining the values for the standard deviation of both, we then multiplied each standard deviation by 3. For our final calculation we subtracted by the mean of each value, thus, giving us the value to compare to 16000N to check for eligibility.
    
    */
    
    steelStream.close();
    graphiteStream.close();
        
    return 0;
}

double mean(vector<int> v)
{
    double sumOfVector = 0, mean = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sumOfVector += v.at(i);
    }
    mean = sumOfVector / v.size();
    return mean;
}

int maxValue(vector<int> v)
{
    int maximum = 0;
    maximum = v[0];
    for(int i = 0; i < v.size(); i++)
    {
        if(maximum < v[i])
        {
            maximum = v[i];
        }
    }
    
    return maximum;
}

int minValue(vector<int> v)
{
    int minimum = v[0];
    for(int i = 0; i < v.size(); i++)
    {
        if(minimum > v[i])
        {
            minimum = v[i];
        }
    }
    
    return minimum;
}

double variance(vector<int> v)
{
   double mean1, mean2, var, size;
   mean1 = mean(v);
   size = v.size();
   for(int ix = 0; ix < size; ix++)
   {
      v[ix] = mean1 - v[ix];
      v[ix] = pow(v[ix],2);
   }
   
   var = mean(v);
   return var;
}

double standardDeviation(double var)
{
   return sqrt(var);  
}
