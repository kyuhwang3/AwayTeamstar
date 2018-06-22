var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var clientSchema = new Schema({
    name: String,
});

module.exports = mongoose.model('client', clientSchema);