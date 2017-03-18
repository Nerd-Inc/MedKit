const cheerio = require('cheerio');
const request = require('request');

var link = 'http://symptomchecker.webmd.com/single-symptom?symptom=pain-or-discomfort&symid=1&loc=22';

request(link, function (err, res, data){
	if (err && res.statusCode !== 200) return console.log(err.stack);
	var $ = cheerio.load(data);
	$('div.intro').each(function(i, element){
      var p = $('div.intro p');
      console.log(p.text());
	})
});
