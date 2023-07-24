# retrieve your $IAM_SERVICE_CREDENTIALS_USERNAME, $IAM_SERVICE_CREDENTIALS_PASSWORD, and $IAM_SERVICE_CREDENTIALS_URL from the
# Service credentials associated with your IBM Cloud.

export IAM_SERVICE_CREDENTIALS_USERNAME=
export IAM_SERVICE_CREDENTIALS_PASSWORD=
export IAM_SERVICE_CREDENTIALS_URL=
#API Key=



curl --basic --user $IAM_SERVICE_CREDENTIALS_USERNAME:$IAM_SERVICE_CREDENTIALS_PASSWORD $IAM_SERVICE_CREDENTIALS_URL/identity/token

# the above CURL request will return an auth token that you will use as $IAM_AUTH_TOKEN in the scoring request below
# TODO: manually define and pass values to be scored below

export IAM_AUTH_TOKEN=DSpWlRI6o3CydLjnBfwQ2dWqUff1txPDWL9ptWoijBT6
export ARRAY_OF_INPUT_FIELDS=
export ARRAY_OF_VALUES_TO_BE_SCORED=
export ANOTHER_ARRAY_OF_VALUES_TO_BE_SCORED=


curl -X POST --header 'Content-Type: application/json' --header 'Accept: application/json' --header "Authorization: Bearer  $IAM_AUTH_TOKEN" -d '{"fields": [$ARRAY_OF_INPUT_FIELDS],"values": [$ARRAY_OF_VALUES_TO_BE_SCORED, $ANOTHER_ARRAY_OF_VALUES_TO_BE_SCORED]}' https://us-south.ml.cloud.ibm.com/ml/v4/deployments/316d7500-d4dd-4b39-87da-6e4e7ac3a136/predictions\
