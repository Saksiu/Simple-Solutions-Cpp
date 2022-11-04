#include <iostream>
#include <vector>

/*given a sorted vector of Integers, find a pair of elements that sum up to a val value*/

bool sumOfTwo(const std::vector<int>& v,int val, int& i, int& j){

	/*start from the edges of the vector*/
	i=0;
	j=v.size()-1;

	/*while both pointers aren't in the middle*/
	while(i<j)
		if(v.at(i)+v.at(j)==val)		//if found answer
			return true;
		else if(v.at(i)+v.at(j)<val)	//if sum of pair smaller than val
			i++;
		else							//if sum of pair bigger than val
			j--;
	i=j=-1;
	return false;						//if there aren't any pairs summing up to val
}

int main()
{
	std::vector<int> a{ 2, 4, 5, 8, 9, 11, 13, 15 };	//always sorted
	int i,j,val=21;

	sumOfTwo(a,val,i,j);
	std::cout<<i<<" "<<j;
}