# boostcamp lecture: File, Exception, Log handling

# ---------------------------try, except, else, finally
a = [1, 2, 3, 4, 5]
for i in range(10):  # 0 to 9
    try:
        print(i, 10 // i)
        print(a[i])
        print(v)
    except ZeroDivisionError:
        print("Error")
        print("Not divided by 0")
    except IndexError as e:  # Log of IndexError is contained in 'e'
        print(e)  # = name 'v' is not defined
    except (
        Exception
    ) as e:  # Overall exception handling, but DO NOT USE because it is not a exact exception handling
        print(e)
    else:
        # In case of no exception
        print("else case")
    finally:
        # Always launched code whether error occurs or not
        print("finally case")

# ---------------------------raise
for i in range(10):
    # When you didn't make your code properly -> use NotImplementedError
    raise NotImplementedError  # Stop the code


# ---------------------------assert
def get_binary_number(decimal_number):
    # assert is used for debugging. When the condition of assert() is False, assert() raise AssertionError.
    assert isinstance(
        decimal_number, int
    )  # isinstance(): Check if the object is an integer.
    return bin(decimal_number)


print(get_binary_number(10))

# ---------------------------Memo
# 1. 'if' is used when you handle logical problem.
#    -> exception handling is used when you handle not intended problem. ex)user mistakes...
# 2. Built-in Exception
#    a. IndexError: When you try to access an index beyond the range of a list.
#    b. NameError: When you reference a variable that does not exist.
#    c. ZeroDivisionError: When you try to divide by 0
#    d. ValueError: When you try to convert a number or string that cannot be converted.
#    e. FileNotFoundError: When you reference file that does not exist.
