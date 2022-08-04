


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
//         ✔️ Solution - I (Using Explicit Stack)

// The reverse polish is a mathematical notation in which operators follow their operands. So, we will get the operands first and then the operators.

// So, we need to store all the previous operands in order that we receive. If we get a operator at anytime, we know that it must be operated on the previous two operands. The result that we get will act as operand for future operations and so it must be stored as well. We can use a stack to store all the operands. The algorithm can be summarized as -

// If the current token is a operand (number), push it into the stack
// If the token is a operator, pop the top two operands from the stack. Find the result of the operation using the operator and two operands and push the result back into stack
// Finally, the stack will contain the result of evaluated reverse polish expression.
        
        stack<int> st;
         
        for(int i=0;i<tokens.size();i++){ 
            int val1=0;
            int val2=0;
            
            if(tokens[i]=="+"){ 
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val1+val2;
                st.push(ans);
            }
            else if(tokens[i]=="-"){
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val2-val1;
                st.push(ans);
            }
            else if(tokens[i]=="/"){
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val2/val1;
                st.push(ans);
            }
            else if(tokens[i]=="*"){
                val1=st.top();
                st.pop();
                val2=st.top();
                st.pop();
                int ans=val2*val1;
                st.push(ans);
            }
            else st.push(stoi(tokens[i])); 
        }
        return st.top();
      
//         ✔️ Solution - III (Using input vector as stack)

// If we are allowed to modify the input vector, we can optimize the space usage by using the input vector itself as a stack rather than an explicit stack.

// Here, we will maintain a pointer top which will point to the top index of tokens (our implicit stack). Everytime we receive a integer token, we will push it at the index pointed by top. Similarly, when we receive an operator, we can pop the top two operands and after computing the result on them, push it back into tokens.

// The only important thing here is properly maintaining the top pointer, so that we correctly access the elements the operands.

// int evalRPN(vector<string>& tokens) {
// 	int top = 0;
// 	for(auto& t : tokens) 
// 		if(t == "+" || t == "-" || t == "*" || t == "/") {
// 			int op1 = stoi(tokens[--top]); 
// 			int op2 = stoi(tokens[--top]); 
// 			if(t == "+") op1 = op2 + op1;
// 			if(t == "-") op1 = op2 - op1;
// 			if(t == "/") op1 = op2 / op1;
// 			if(t == "*") op1 = op2 * op1;   
// 			tokens[top++] = to_string(op1);
// 		}
// 		else tokens[top++] = t;
// 	return stoi(tokens[0]);
// }
// Time Complexity : O(N)
// Space Complexity : O(1)

}
    
};