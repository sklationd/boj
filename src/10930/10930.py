import hashlib

str1 = input()
result = hashlib.sha256(str1.encode())
print(result.hexdigest())