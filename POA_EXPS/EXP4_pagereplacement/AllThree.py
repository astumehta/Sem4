def fifo(frames, pages):
    hits = 0
    miss = 0
    index = 0
    for i in range(len(pages)):
        flag = 1
        for j in range(len(frames)):
            if frames[j] == pages[i]:
                flag = 0
                hits += 1
                break
        if flag:
            miss += 1
            frames[index] = pages[i]
            index = (index + 1) % len(frames)
        print(frames)
    return hits, miss

def lru(frames, pages):
    hits = 0
    miss = 0
    recent = [-1] * len(frames)
    for i in range(len(pages)):
        flag = 1
        for j in range(len(frames)):
            if frames[j] == pages[i]:
                recent[j] = i
                flag = 0
                hits += 1
                break
        if flag:
            miss += 1
            index = recent.index(min(recent))
            frames[index] = pages[i]
            recent[index] = i
        print(frames)
    return hits, miss

def find_optimal(frames, pages, index):
    farthest = -1
    farthest_index = -1
    for i in range(len(frames)):
        try:
            cur_farthest = pages[index+1:].index(frames[i])
            if cur_farthest > farthest:
                farthest = cur_farthest
                farthest_index = i
        except ValueError:
            return i
    return farthest_index

def optimal(frames, pages):
    hits = 0
    miss = 0
    for i in range(len(pages)):
        flag = 1
        for j in range(len(frames)):
            if frames[j] == pages[i]:
                flag = 0
                hits += 1
                break
        if flag:
            miss += 1
            if -1 in frames:
                frames[frames.index(-1)] = pages[i]
            else:
                index = find_optimal(frames, pages, i)
                frames[index] = pages[i]
        print(frames)
    return hits, miss

# def print_frames(frames):
#     for frame in frames:
#         if frame == -1:
#             print(" ", end="\t")
#         else:
#             print(frame, end="\t")
#     print()

def main():
    print("Dev Pandey C1 - C034 60004220008")
    frames = []
    pages = []
    n = int(input("Enter the number of frames: "))
    p = int(input("Enter the number of pages: "))
    for i in range(p):
        pages.append(int(input("Enter the page number: ")))
    for i in range(n):
        frames.append(-1)
    print("FIFO:")
    fifo_hits, fifo_miss = fifo(frames.copy(), pages.copy())
    print(f"Number of hits: {fifo_hits}")
    print(f"Number of miss: {fifo_miss}")
    print(f"Hit %: {(fifo_hits/(fifo_hits+fifo_miss))*100}")
    print(f"Miss %: {(fifo_miss/(fifo_hits+fifo_miss))*100}")
    print("\nLRU:")
    lru_hits, lru_miss = lru(frames.copy(), pages.copy())
    print(f"Number of hits: {lru_hits}")
    print(f"Number of miss: {lru_miss}")
    print(f"Hit %: {(lru_hits/(lru_hits+lru_miss))*100}")
    print(f"Miss %: {(lru_miss/(lru_hits+lru_miss))*100}")
    print("\nOptimal:")
    optimal_hits, optimal_miss = optimal(frames.copy(), pages.copy())
    print(f"Number of hits: {optimal_hits}")
    print(f"Number of miss: {optimal_miss}")
    print(f"Hit %: {(optimal_hits/(optimal_hits+optimal_miss))*100}")
    print(f"Miss %: {(optimal_miss/(optimal_hits+optimal_miss))*100}")

if __name__ == "_main_":
    main()