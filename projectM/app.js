// app.js

// [LOAD PACKAGES]
var express     = require('express');
var app         = express();
var bodyParser  = require('body-parser');
var mongoose    = require('mongoose');

// [CONFIGURE APP TO USE bodyParser]
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

// [CONFIGURE SERVER PORT]
var port = process.env.PORT || 3003;

// [CONFIGURE ROUTER]
var Client = require('./models/client');
var router = require('./router')(app, Client);

var db = mongoose.connection;
db.on('error', console.error);
db.once('open', function(){
    // CONNECTED TO MONGODB SERVER
    console.log("Connected to mongod server");
});

mongoose.connect('mongodb+srv://kkim0129:Enfl89qjs!@cluster0-3yigh.mongodb.net/test?retryWrites=true');

// [RUN SERVER]
var server = app.listen(port, function(){
    console.log("Express server has started on port " + port)
});
