#include<bits/stdc++.h>

using namespace std;

class Polynomial {

    int capacity;
    public:
        int *degCoeff;
        Polynomial()
        {
            int i,j,k,l;
            degCoeff=new int[5];
            for(i=0;i<=5-1;i++)
            {
                degCoeff[i]=0;
            }
            capacity=5;
        }

        Polynomial(Polynomial const &d)
        {
            int i,j,k,l;
            degCoeff=new int[d.capacity];
            for(i=0;i<=d.capacity-1;i++)
            {
                degCoeff[i]=d.degCoeff[i];
            }

            capacity=d.capacity;
        }

        void operator = (Polynomial const &d)
        {
            int i,j,k,l;
            degCoeff=new int[d.capacity];
            for(i=0;i<=d.capacity-1;i++)
            {
                degCoeff[i]=d.degCoeff[i];
            }

            capacity=d.capacity;
        }

        void print ()
        {
            int i,j,k,l;
            for(i=0;i<=capacity-1;i++)
            {
                if(degCoeff[i]!=0)
                {
                    cout<<degCoeff[i]<<'x'<<i<<' ';
                }
            }

            cout<<'\n';
        }

        void setCoefficient(int degree,int coeff)
        {
            int i,j,k,l;
            if(degree>capacity-1)
            {
                int capacity1=capacity;
                while(capacity1-1<degree)
                {
                    capacity1*=2;
                }

                int *newDegCoeff=new int[capacity1];
                for(i=0;i<=capacity1-1;i++)
                {
                    newDegCoeff[i]=0;
                }
                for(i=0;i<=capacity-1;i++)
                {
                    newDegCoeff[i]=degCoeff[i];
                }

                delete []degCoeff;
                degCoeff=newDegCoeff;
                capacity=capacity1;
            }

            degCoeff[degree]=coeff;
        }

        Polynomial operator + (Polynomial const &d) const
        {
            int i,j,k,l;
            Polynomial d1;
            i=0;
            j=0;
            while(i<=capacity-1 && j<=d.capacity-1)
            {
                int num=degCoeff[i]+d.degCoeff[i];
                d1.setCoefficient(i,num);
                i++;
                j++;
            }
            while(i<=capacity-1)
            {
                d1.setCoefficient(i,degCoeff[i]);
                i++;
            }
            while(j<=d.capacity-1)
            {
                d1.setCoefficient(j,d.degCoeff[j]);
                j++;
            }

            return d1;
        }

        Polynomial operator - (Polynomial const &d) const
        {
            int i,j,k,l;
            Polynomial d1;
            i=0;
            j=0;
            while(i<=capacity-1 && j<=d.capacity-1)
            {
                int num=degCoeff[i]-d.degCoeff[i];
                d1.setCoefficient(i,num);
                i++;
                j++;
            }
            while(i<=capacity-1)
            {
                d1.setCoefficient(i,degCoeff[i]);
                i++;
            }
            while(j<=d.capacity-1)
            {
                d1.setCoefficient(j,-1*d.degCoeff[j]);
                j++;
            }

            return d1;
        }

        Polynomial operator * (Polynomial const &d) const
        {
            int i,j,k,l;
            Polynomial d1;
            for(i=0;i<=capacity-1;i++)
            {
                for(j=0;j<=d.capacity-1;j++)
                {
                    int deg=i+j;
                    int coeff=degCoeff[i]*d.degCoeff[j];
                    if(d1.capacity-1<deg)
                    {
                        d1.setCoefficient(deg,coeff);
                    }
                    else
                    {
                        d1.degCoeff[deg]+=coeff;
                    }

                }
            }

            return d1;
        }

};


int main()
{
    int count1,count2,choice;
    cin >> count1;
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++)
        cin >> degree1[i];
    for(int i=0;i < count1; i++)
        cin >> coeff1[i];

    Polynomial first;
    for(int i = 0; i < count1; i++)
        first.setCoefficient(degree1[i],coeff1[i]);

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++)
        cin >> degree2[i];
    for(int i=0;i < count2; i++)
        cin >> coeff2[i];

    Polynomial second;
    for(int i = 0; i < count2; i++)
        second.setCoefficient(degree2[i],coeff2[i]);

    cin >> choice;

    switch(choice){
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
    }

    return 0;
}
