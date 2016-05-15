import httplib
import  json

receipt = 'Your transactionReceiptString';

jsonStr = json.dumps({"receipt-data": receipt})

#connect = httplib.HTTPSConnection("buy.itunes.apple.com")
# sandbox
connect = httplib.HTTPSConnection("sandbox.itunes.apple.com")
headers = {"Content-type": "application/json"}
connect.request("POST", "/verifyReceipt", jsonStr)
result = connect.getresponse()
data = result.read()
connect.close()
decodedJson = json.loads(data)

print decodedJson

# status = decodedJson[u'status']
# if status == 0:
	#success
# elif status == 21007:

# else:
	#failed