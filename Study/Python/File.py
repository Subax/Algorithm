# List: same rule as a array
list1 = [1, 2, 3, 4]  # To declare list, using '[]'
list3 = list([1, 2, 3])  # List can be declared via list()
list4 = list(
    [1, 2, 3], [4, 5, 6]
)  # List can be declared to use double array, triple array...
list5 = list()
list6 = []  # We can make empty list!

list_copied = list1[:]  # To copy value of other list, you should use list slicing
list_wrong_copied = list1  # This is memory copy, not value copy

list1.append(1, 2)  # Insert '2' in list1[1]
list1.append(2)  # Insert '2' in last position of list1

list1.pop(1)  # Delete value of list[1]
list1.pop()  # Delete value of last position of list[1]

list1.sort()  # Ascending sort value
list1.reverse()  # Change order of list

# -----------------------------
# Tuple: Immutable, high speed than list
tuple1 = (1, 2, 3, 4)
tuple2 = 1, 2, 3, 4

tuple3 = (1,)  # If tuple have only one value, You must declare value including ','
tuple3_wrong = 1  # This notation will be classify as a data

tuple4 = tuple([1, 2, 3, 4])
tuple5 = tuple(1, 2, 3, 4)  # Tuple in tuple

tuple6 = "10", 10, "ten"  # Packing
a, b, c = tuple6  # Unpacking

print(1 in tuple1)  # If tuple1 include '1', It will be print 'True'
print(10 in tuple1)  # False

# -----------------------------
# Set: No order, No duplicate value
set1 = {1, 2, 3}
set2 = set(1, 2, 3)
set3 = set("pythonn")  # set3 = {'p', 'y', 't', 'h', 'o', 'n'}

emp_set1_wrong = {}  # It will be classified as a dictionary
emp_set1 = set()

set1.add(4)  # add '4' to set1
set1.update(5, 6, 7)  # To add several element to set, use update()
set1.remove(7)  # Remove '7' in set1

set_union = set1 | set2
set_difference = set1 - set2
set_intersaction = set1 & set2
set_complementary = set1 ^ set2

# -----------------------------
# Dictionary: Mapping(value - key)
dict1 = {"one": 1, "two": "둘", "circumference": 3.14}
dict2 = dict({"one": 1, "soyoon": "girlfreind"})
dict3 = dict([("one", 1), (3.14, "원주율")])
dict4 = dict(one=1, two=2)  # If key is string, you can use '=' instead of ':'

dict5 = {
    (1, 2): ["one", "two"]
}  # Key must be IMMUTABLE DATA like tuple, string, integer, etc.
