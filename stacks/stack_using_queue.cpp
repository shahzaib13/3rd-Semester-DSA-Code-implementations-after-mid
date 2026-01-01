/*
Notes by Shahzaib Saleem:
main logic:
hum  2 queues use kar rhy, q2 mai hum value ko add kar rhy,
pir hum check kar rhy ky agr q1 mai koi bhi value hai, unn sab ko q2 mai add kr do, jab tk q1 khali na hojye,
phir hum uss sab q2 ki values ko q1 mai add kar rhy
iss trha hum queue sy LIFO acheive kar rhy,
addition hmri intial q2 mai hogi, but pop/remove hum q1 sy kary gy
Example:
intial:  q2,q1= empty
1st insert(val = 10):  
    q2 = 10, q1 = empty, 
    lkin ab hum yeh q2 ki value ko q1 ma add kar dy gy tuo:
    q1 = 10, q2 = empty
2nd Inset (val = 20): 
    q2 = 20, q1 = 10, 
    tuo ab hum phly q1 ki value ko q2 mai add kary gy:
    q2 = 20 ,10  and q1 = empty,
    isky baad dobra q2 ko khali kary gy and values ko q1 mai daal dy gy:
    q1 = 20, 10 , q2  = empty
2nd Inset (val = 30): 
    q2 = 30, q1 = 20, 10, 
    tuo ab hum phly q1 ki value ko q2 mai add kary gy:
    q2 =30, 20 ,10  and q1 = empty,
    isky baad dobra q2 ko khali kary gy and values ko q1 mai daal dy gy:
    q1 =30, 20, 10 , q2  = empty
now hum dekh skty ky: 
hmri values add krny ka order tha :1st:  10 , 2nd: 20, 3rd: 30.
but agr ab hum q1 sy value ko pop kary gy(Fifo style mai)tuo humy wapis: 30 20 10 (Lifo  style mai milygi)
*/
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Stack
{
        queue<T> q1;
        queue<T> q2;

    public:
        bool isEmpty()
        {
            return q1.empty();
        }

        void push(T val)
        {
            q2.push(val);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            while (!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }

        bool pop()
        {
            if (isEmpty())
                return false;
            q1.pop();
            return true;
        }

        T top()
        {
            if (isEmpty())
                return T{};
            return q1.front();
        }
};

int main()
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1.top();
}
