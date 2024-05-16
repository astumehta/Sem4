def index(f,pages,start):
    indexval=-1
    dist=-1
    for i,page in enumerate(f):
        if page not in pages[start:]:
            return i
        else:
            distance=pages[start:].index(page)
            if distance>dist:
                dist=distance
                indexval=i
    return indexval

def optimal(frames,pages):
    f=[-1]*frames
    miss=0
    hit=0
    for i,page in enumerate(pages):
        if page in f:
            hit+=1
        else:
            miss+1
            if -1 in f:
                indexval=f.index(-1)
                f[indexval]=page
            else:
                replaceindex=index(f,pages,i)
                f[replaceindex]=page
        print(f"Frames {f}")


    


