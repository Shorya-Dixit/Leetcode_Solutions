class Solution {
public:
    string intToRoman(int num) {
    vector<char>s;
            if(num/1000>0)
            {
              s.insert(s.end(),num/1000,'M');
              num%=1000;
            }
            if(num>=900) {s.insert(s.end(),'C');s.insert(s.end(),'M');num%=900;}
            if(num/500>0)
            {
              s.insert(s.end(),num/500,'D');
              num%=500;  
            }
            if(num>=400) {s.insert(s.end(),'C');s.insert(s.end(),'D');num%=400;}
            if(num/100>0)
            {
              s.insert(s.end(),num/100,'C');
              num%=100; 
            }
            if(num>=90) {s.insert(s.end(),'X');s.insert(s.end(),'C');num%=90;} 
            if(num/50>0)
            {
              s.insert(s.end(),num/50,'L');
              num%=50;  
            }
            if(num>=40) {s.insert(s.end(),'X');s.insert(s.end(),'L');num%=40;}
            if(num/10>0)
            {
              s.insert(s.end(),num/10,'X');
              num%=10;
            }
            if(num>=9) {s.insert(s.end(),'I');s.insert(s.end(),'X');num%=9;}  
            if(num/5>0)
            {
              s.insert(s.end(),num/5,'V');
              num%=5; 
            }
            if(num>=4) {s.insert(s.end(),'I');s.insert(s.end(),'V');num%=4;} 
            s.insert(s.end(),num,'I');
            string ss(s.begin(),s.end());
            return ss;
    }
};
// check last submission too