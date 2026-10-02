/*
The Solution: Sort + Monotonic Stack
To solve this cleanly, we process cars from closest to the target to farthest from the target (descending order of position).

Pair each car's position and speed, then sort them by position in descending order.

Iterate through them, calculating each car's individual arrival time (double).

Use a stack to track the fleet times:

If the current car takes more time than the car (or fleet) ahead of it (time > st.top()), it means it can never catch up to them. It must form a new fleet, so we push its time to the stack.

If it takes less or equal time, it catches up and merges into the fleet ahead of it. We don't push anything.

The size of the stack at the end is our total number of fleets!
*/


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        vector<pair<int, int>> cars;
        for(int i = 0; i < n; i++)
        {
            cars.push_back({position[i], speed[i]});
        }  
        sort(cars.rbegin(), cars.rend()); // rbrgin => reverse begin -> descending order
        stack<double> timeSt;

        for(auto& car : cars)
        {
            double time = double(target - car.first) / car.second;
            if(timeSt.empty() || time > timeSt.top())
            {
                timeSt.push(time);
            }
        }
        return timeSt.size();
    }
};