//
//  main.cpp
//  Assignment
//
//  Created by Rameen Mahmood on 18/09/2019.
//  Copyright © 2019 ENGR-AD101. All rights reserved.
//

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    double length=0, depth=0, permanent_load=0, variable_load=0, characteristic_load=0,bending_moment=0, Ws=0, sforce=0, design_action=0, width=0;
    const double permanent_load_margin = 0.6;
    const double variable_load_margin = 0.2;
    const double concrete_unit_weight = 25;
    int sentinel = 1;
    do
    {
        cout<<"The software designs a rectangular beam. Enter the beam specifications"<<endl;
        cout<<"Length: ";
        cin>> length;
        cout<<"Permanent load(gk, kN/m): ";
        cin>> permanent_load;
        cout<<"Variable load(qk, kN/m): ";
        cin>> variable_load;
        while (length <= 0)
        {
            cout<<"Invalid length entry, enter again"<<endl;
            cin>>length;

            while (permanent_load <= 0)
            {
                cout<<"Invalid permanent load entry, enter again"<<endl;
                cin>>permanent_load;

                while (variable_load <= 0)
                {
                    cout<<"Invalid variable load entry, enter again"<<endl;
                    cin>>variable_load;
                }
            }
        }
        depth = length/14;
        width = 0.4 * depth;
        Ws = depth * width * concrete_unit_weight;
        characteristic_load= Ws + permanent_load;
        design_action=(1+ permanent_load_margin)* permanent_load +(1+variable_load_margin)*variable_load;
        sforce = (design_action*length)/2;
        bending_moment= (design_action *length *length)/8;
        cout<<"Here is a summary of the beam design: "<<endl;
        cout<<"The minimum values for the size of the beam are: "<<endl;
        cout<<"Depth: "<<ceil(depth *1000)<<" mm"<<endl; //multiplying by 1000 to convert to milimeters
        cout<<"Width: "<<ceil(width*1000)<<" mm"<<endl;
        cout<<"The total characteristic load= "<<characteristic_load<<" kN/m"<<endl;
        cout<<"Shear force (V)= "<<sforce<<" kN"<<endl;
        cout<<"Bending moment= "<<bending_moment<<" kNm"<<endl;
         cout<<"Enter -1 to exit or any other number to repeat"<<endl;
         cin>>sentinel;
    } while (sentinel != -1);
    cout<<"Program terminating"<<endl;
    return 0;
}
