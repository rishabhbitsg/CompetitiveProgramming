class SimilarUserDetection:
	def haveSimilar(self, handles):
		same = {"O" : "0", "0" : "O", "l" : "1I", "1": "lI", "I" : "1l"}
		result = "Similar handles not found"
		flag1 = False
		for i in xrange(len(handles)):
			for j in xrange(i + 1, len(handles)):
				if len(handles[i]) == len(handles[j]):
					flag = True
					for k in xrange(len(handles[i])):
						if handles[i][k] != handles[j][k]:
							if handles[i][k] in same:
								if handles[j][k] not in same[handles[i][k]]:
									flag = False 
									break
							else:
								flag = False
								break
					if flag:
						result = "Similar handles found"
				if flag1:
					break
			if flag1:
				break
		return result

