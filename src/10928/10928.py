import hashlib

str1 = input()
result = hashlib.sha1(str1.encode())
print(result.hexdigest())