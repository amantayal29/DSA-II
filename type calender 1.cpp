class MyCalendar {
public:
    map<int ,int >seg ;
    map<int ,int >lazy ; 
    MyCalendar() {
    }
    int update(int ind, int low, int high, int l ,int r )
    {
        if(high<l || r<low)return 0 ; 
        if(low>=l && high<=r)
        {
            seg[ind]++ ;
            lazy[ind]++; 
            
           return seg[ind] ;
        }
        
            int mid = (low+high)/2 ;
            update(2*ind+1 , low ,mid ,l ,r ); 
            update(2*ind+2 , mid+1 ,high , l ,r ); 
        return seg[ind] = lazy[ind] +max(seg[2*ind+1] , seg[2*ind+2]); 
        
    }
int update1(int ind, int low, int high, int l ,int r )
    {
        if(high<l || r<low)return 0 ; 
        if(low>=l && high<=r)
        {
            seg[ind]-- ;
            lazy[ind]--; 
            
           return seg[ind] ;
        }
        
            int mid = (low+high)/2 ;
            update1(2*ind+1 , low ,mid ,l ,r ); 
            update1(2*ind+2 , mid+1 ,high , l ,r ); 
        return seg[ind] = lazy[ind] +max(seg[2*ind+1] , seg[2*ind+2]); 
        
    }
    
    
    bool book(int start, int end) {
        
       if(update(0 ,0 , 1000000000 , start, end-1)==1)
           return true; 
        else
        {
            update1(0 ,0 , 1000000000 , start, end-1) ;
            return false ;
        }
             
    }
};
