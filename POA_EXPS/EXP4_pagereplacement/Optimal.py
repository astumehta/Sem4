def index(f, pages, start):
    index_val = -1
    dist = -1
    for i, page in enumerate(f):
        if page not in pages[start:]:
            return i
        else:
            distance = pages[start:].index(page)
            if distance > dist:
                dist = distance
                index_val = i
    return index_val

def Optimal(frames, pages):
    f = [-1] * frames
    hits = 0
    miss = 0
    for i, page in enumerate(pages):
        if page in f:
            hits += 1
        else:
            miss += 1
            if -1 in f:
                index_val = f.index(-1)
                f[index_val] = page
            else:
                replace_index = index(f, pages, i)
                f[replace_index] = page
        print(f"Frames: {f}")
    return hits, miss


frames = int(input("Enter the number of frames: "))
pages = list(map(int, input("Enter the pages (space-separated): ").split()))

hits, miss = Optimal(frames, pages)
print("Hits:", hits)
print("Misses:", miss)
