class foo(object):
	def __init__(self, a):
		self.a = a

	def __str__(self):
		return str(self.a)

a = foo(2)
b = a
print(a)
print(b)