package MyPriorityQueue;

import org.omg.PortableInterceptor.INACTIVE;

import java.util.ArrayList;
import java.util.List;

public class MyPriorityQueue {
    private List<Integer> list = new ArrayList<Integer>();

    //add all elements into the priorityqueue
    public void add_all(int[] m) {
        for(int n : m) {
            list.add(n);
            popup();
        }

    }

    //make the last added number in its right position
    private void popup() {
        int length = list.size();
        int childrenIndex = length - 1;
        while (true) {
            if(length == 1 || length == 0 || childrenIndex == 0) {
                break;
            } else {
                int parentIndex = (childrenIndex - 1) / 2;
                if(list.get(parentIndex) > list.get(childrenIndex)) {
                    int parent_value = list.get(parentIndex);
                    int children_value = list.get(childrenIndex);
                    list.set(parentIndex, children_value);
                    list.set(childrenIndex, parent_value);
                    childrenIndex = parentIndex;
                } else {
                    break;
                }
            }
        }
    }

    //exchange the potions of first and last numbers,
    //delete the last element
    //make the first number to the right position
    public int downward() {

        int current = 0;
        if(list.size() == 0)
            return -1;
        int first_value = list.get(0);
        int last_value = list.get(list.size() - 1);
        while (true) {
            if(list.size() == 0 || list.size() == 1 || current * 2 + 1 > list.size() - 1) {
                break;
            } else {
                int left_children_index = current * 2 + 1;
                int right_children_index = left_children_index + 1;
                int current_value = list.get(current);
                int left_value = list.get(left_children_index);

                if(right_children_index < list.size()) {
                    int right_value = list.get(right_children_index);
                    int min_value = left_value < right_value ? left_value : right_value;
                    int min_index = left_value < right_value ? left_children_index : right_children_index;
                    if(current_value > min_value) {
                        list.set(current, min_value);
                        list.set(min_index, current_value);
                        current = min_index;
                    } else
                        break;
                } else if(right_children_index > list.size() - 1) {
                    if(current_value > left_value) {
                        list.set(current, left_value);
                        list.set(left_children_index, current_value);
                        current = left_children_index;
                    } else
                        break;
                } else
                    break;
            }
        }
        return first_value;
    }

    //print all priorityqueue elements
    public void print() {
        for(Integer n : list) {
            System.out.print(n);
        }
        System.out.println();
    }

    //remove the smallest number(the top number of the heap), and then reorder the heap
    public int remove() {
        int last_index = list.size() - 1;
        int last_value = list.get(last_index);
        int first_value = list.get(0);
        list.set(0, last_value);
        list.remove(last_index);
        downward();
        return first_value;
    }

}
