class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     

     stack<int>s;

     for(int i=0;i<tokens.size();i++)
     {
        

        if(tokens[i]!="+"&&tokens[i]!="-"&& tokens[i]!="*"&&tokens[i]!="/")
        {
            s.push(stoi(tokens[i]));
        }


     else if(s.size()>=2)
     {
        int op2=s.top();
        s.pop();
        int op1=s.top();
        s.pop();
       


        string ch=tokens[i];

        if(ch =="+")
        {
           s.push(op1+op2);
        }
        else  if(ch =="-")
        {
        s.push(op1-op2);
        }
        else  if(ch =="*")
        {
        s.push(op1*op2);
        }
        else  
        {
        s.push(op1/op2);
        }

    }  
     }

        return s.top();
        
    }
};