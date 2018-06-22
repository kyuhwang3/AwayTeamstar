// routes/index.js

module.exports = function (app, Client) {
    app.get('/', function (req, res){
        res.end("Project M");
    });
    app.get('/api/clients', function (req, res) {
        Client.find(function(err, books){
            if(err) return res.status(500).send({error: 'database failure'});
            res.json(books);
        })
    });

    app.post('/api/clients', function (req, res) {
        var client = new Client();
        client.name = req.body.name;
        console.log(req.body.name);
        //console.log(req.body);
        client.save(function(err){
            if(err){
                console.error(err);
                res.json({result: 0});
                return;
            }
    
            res.json({result: 1});
    
        });
    });
}