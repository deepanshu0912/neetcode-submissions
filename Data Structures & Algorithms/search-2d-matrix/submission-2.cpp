class Solution {
public:
    int row(vector<vector<int>>& matrix, int target)
    {
        int low=0,high=matrix.size()-1;
        int mid=low+(high-low)/2;
        while(low<=high)
        {
            
            int a=matrix[mid][0];
            if(low==high){return mid;}
            if(a<=target && matrix[mid+1][0]>target){return mid;}
            else if(a>target){high=mid-1;}
            else{low=mid+1;}
            mid=low+(high-low)/2;
        }
        return mid;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a=row(matrix,target);
        int i=0,j=matrix[a].size()-1;
        int mid=(j+i)/2;
        while(j>=i)
        {
            cout<<i<<" mid"<<j<<" "<<mid<<endl;
            if(matrix[a][mid]==target){return true;}
            else if(matrix[a][mid]>target)
            {
                j=mid-1;
            }
            else{i=mid+1;}
            mid=(j+i)/2;
        }
        return false;
    }
};
