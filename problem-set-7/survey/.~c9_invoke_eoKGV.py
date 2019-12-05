import cs50
import csv

from flask import Flask, jsonify, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Reload templates when they are changed
app.config["TEMPLATES_AUTO_RELOAD"] = True


@app.after_request
def after_request(response):
    """Disable caching"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def get_index():
    return redirect("/form")


@app.route("/form", methods=["GET"])
def get_form():
    return render_template("form.html")


@app.route("/form", methods=["POST"])
def post_form():

    name = request.form.get("name")
    shoe = request.form.get("shoe")
    color = request.form.get("color")
    premium = request.form.get("premium")
    if name == "" or shoe=="":
        return render_template("error.html",message="No name or show input")


    if premium == "on":
        premium = "Premium"
    else:
        premium = "Non-Premium"

    with open('survey.csv', 'w', newline='') as csvfile:
        spamwriter = csv.writer(csvfile, delimiter=' ', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        spamwriter.writerow([name] + [shoe] + [color] + [premium])
    return render_template("sheet.html")


@app.route("/sheet", methods=["GET"])
def get_sheet():
    return render_template("sheet.html")
