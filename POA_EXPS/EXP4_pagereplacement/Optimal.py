def farthest_index(f,pages, startindex):
        farthest_index = -1
        farthest_dist = -1
        for i, page in enumerate(f):
            if page not in pages[startindex:]:
                return i
            else:
                distance = pages[startindex:].index(page)
                if distance > farthest_dist:
                    farthest_dist = distance
                    farthest_index = i
        return farthest_index

def Optimal(frames, pages):
        f = [-1]*frames
        hits = 0
        miss = 0
        for i, page in enumerate(pages):
            if page in f:
                hits += 1
            else:
                miss += 1
                if -1 in f:
                    index = f.index(-1)
                    f[index] = page
                else:
                    replace_index = farthest_index(f,pages,i)
                    f[replace_index] = page
            print(f"Frames:{f}")
        return hits, miss