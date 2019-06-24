import os

if __name__ == "__main__":
    for root, dirs, files in os.walk("pat/Basic Level/"):
        if len(root.split("/")) != 3 or "bin" in root or "obj" in root:
            continue
        name = root.split("/")[2]
        nname = " ".join(name.split(" ")[1:])
        if name:
            print(nname)
            with open("pat/Basic Level/" + nname + ".cpp", "wb") as f:
                f.write(open(root + "\main.cpp", "rb").read())
