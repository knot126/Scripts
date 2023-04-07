import codecs

def rot13(m):
  return codecs.encode(m, "rot13")

if __name__ == "__main__":
  while True:
    m = input(">>> ")
    print(rot13(m))
    print()
