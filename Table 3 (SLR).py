# This data helps to calculate the quality of a software in terms of its execution time. Here, 
# X = Execution Time (in seconds)
# Y = Quality Score of Software (out of 10)

X = [3,5,7,9,10,11]
Y = [8,7,6,6,5,4]

#------------------ x_bar ----------------------------

x_bar = sum(X)/len(X)

#------------------ y_bar ----------------------------
y_bar = sum(Y)/len(Y)

#----------------- xi - x_bar ------------------------
x = []
for i in range(0,6):
        x.append(X[i]-x_bar)

#----------------- yi - y_bar -----------------------
y = []
for i in range(0,6):
	y.append(Y[i]-y_bar)

#------------------- sxy -----------------------------
sxy = []
for i in range(0,6):
	sxy.append(x[i]*y[i])
	
sum_sxy = sum(sxy)


#------------------ sx_sq ----------------------------
sx_sq = []
for i in range(0,6):
	sx_sq.append(x[i]*x[i])

	
sum_sx_sq = sum(sx_sq)

#--------------------- b1 -----------------------------
b1 = sum_sxy/sum_sx_sq


#--------------------- b0 -----------------------------
b0 = y_bar - (b1 * x_bar)


#--------------------- TSS ----------------------------
T = []
for i in range(0,6):
	T.append((Y[i]-y_bar) ** 2)
	
TSS = sum(T)

#--------------------- MSS ----------------------------
y_hat = []
M = []
for i in range(0,6):
        y_hat.append(b0 + (b1 * X[i]))

	
for i in range(0,6):
	M.append((y_hat[i] - y_bar) ** 2)
	
MSS = sum(M)

#------------------------- RSS -------------------------
R = []
for i in range(0,6):
	R.append((Y[i]-y_hat[i]) ** 2)
	
RSS = sum(R)

#----------------------- vb0  -------------------------
n = 6
k = 2
MSE = RSS / (n-k)

vb0 = MSE * ((1/n) + ((x_bar*x_bar)/sum_sx_sq))

#----------------------- vb1 ---------------------------
vb1 = MSE / sum_sx_sq
