a=input()
c=lambda h,r=9**9,l=0:a[l:l+r].count(h)
q,r=map(c,"LM")
print(q-c("L",q)+r-c("M",r,q)-min(c("L",r,q),c("M",q)))
