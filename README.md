# espcd-example

Example project that shows how to use the espcd-library and how to automatically build and upload the firmware using github actions.

## Usage

### Sketch

Open `espcd-example.ino`.

Adjust at least the `cert[]` variable, the espcd backend url using `espcd.setUrl(url)` and the product id using `espcd.setProductId(id)`.

The cert variable can be extracted using a webbrowser. Open the backend url (e.g.: https://api.espcd.duckdns.org/), display the certificate chain and select the root ca with the longest validity. Open this PEM certificate and paste the content into the cert variable.

If a product id is specified, the uploaded firmware is automatically associated with that product. This allows the devices using this product to update the firmware automatically.

### Github workflow

Open `.github/workflows/arduino-compile.yml`.

In the matrix, adjust the `fqbn`'s for which the sketch is to be compiled and the corresponding `product` ids.

In the steps adjust the `sketch`, `title` and `description`. (More information [here](https://github.com/espcd/espcd-action)).

Create a new token in the espcd-frontend and add this token as new secret `API_KEY` in the github repository settings.
