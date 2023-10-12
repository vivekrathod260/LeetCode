/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &m) {
        int n = m.length();
        int centre = 0;
        int s = 0, e = n-1;
        int mid = (s+e)/2;
        int temp1 = 0, temp2 = 0, temp3 = 0;

        while(s<=e)
        {
            mid = (s+e)/2;
            temp1 = mid==0 ? INT_MIN : m.get(mid-1);
            temp2 = m.get(mid);
            temp3 = mid==n-1 ? INT_MIN : m.get(mid+1);
            if(temp1<temp2 and temp2>temp3)
            {
                centre = mid;
                break;
            }
            else if(temp1<temp2 and temp2<temp3)
            {
                s = mid+1;
            }
            else if(temp1>temp2 and temp2>temp3)
            {
                e = mid-1;
            }
        }

        s = 0;
        e = centre;
        
        while(s<=e)
        {
            mid = (s+e)/2;

            temp2 = m.get(mid);

            if(temp2 == t)
            {
                return mid;
            }
            else if(temp2 < t)
            {
                s = mid+1;
            }
            else if(t < temp2)
            {
                e = mid-1;
            }
        }

        s = centre;
        e = n-1;

        while(s<=e)
        {
            mid = (s+e)/2;

            temp2 = m.get(mid);

            if(temp2 == t)
            {
                return mid;
            }
            else if(t > temp2)
            {
                e = mid-1;
            }
            else if(temp2 > t)
            {
                s = mid+1;
            }
        }


        return -1;
    }
};