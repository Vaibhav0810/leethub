
// using vector and recursion
// time - O(N^2) bcoz erase takes O(N) and O(N) for recursive thats why O(N^2)
// space- O(N)

int safePos(int n, int k) {
        // code here
        
        
        int index=0;
        vector<int>person;
        for(int i=0;i<n;i++){
            person.push_back(i+1);
        }
        return josh(person,k-1,index);
    }
    
    int josh(vector<int>person,int k,int index){
        if(person.size()==1){
            return person[0];
            
        }
        index=((index+k)%person.size());
        
        person.erase(person.begin()+index);
        
        return josh(person,k,index);
        
    }

// TIme- O(N)
// SPace same
int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        // The position returned by josephus(n - 1, k)
        // is adjusted because the recursive call
        // josephus(n - 1, k) considers the
        // original position k % n + 1 as position 1
        return (josephus(n - 1, k) + k - 1) % n + 1;
}
 
// Driver code
int main()
{
    int n = 14;
    int k = 2;
    cout << "The chosen place is " << josephus(n, k);
    return 0;
}
 
