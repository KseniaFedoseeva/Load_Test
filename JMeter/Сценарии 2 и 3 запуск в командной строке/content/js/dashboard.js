/*
   Licensed to the Apache Software Foundation (ASF) under one or more
   contributor license agreements.  See the NOTICE file distributed with
   this work for additional information regarding copyright ownership.
   The ASF licenses this file to You under the Apache License, Version 2.0
   (the "License"); you may not use this file except in compliance with
   the License.  You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
var showControllersOnly = false;
var seriesFilter = "";
var filtersOnlySampleSeries = true;

/*
 * Add header in statistics table to group metrics by category
 * format
 *
 */
function summaryTableHeader(header) {
    var newRow = header.insertRow(-1);
    newRow.className = "tablesorter-no-sort";
    var cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 1;
    cell.innerHTML = "Requests";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 3;
    cell.innerHTML = "Executions";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 7;
    cell.innerHTML = "Response Times (ms)";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 1;
    cell.innerHTML = "Throughput";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 2;
    cell.innerHTML = "Network (KB/sec)";
    newRow.appendChild(cell);
}

/*
 * Populates the table identified by id parameter with the specified data and
 * format
 *
 */
function createTable(table, info, formatter, defaultSorts, seriesIndex, headerCreator) {
    var tableRef = table[0];

    // Create header and populate it with data.titles array
    var header = tableRef.createTHead();

    // Call callback is available
    if(headerCreator) {
        headerCreator(header);
    }

    var newRow = header.insertRow(-1);
    for (var index = 0; index < info.titles.length; index++) {
        var cell = document.createElement('th');
        cell.innerHTML = info.titles[index];
        newRow.appendChild(cell);
    }

    var tBody;

    // Create overall body if defined
    if(info.overall){
        tBody = document.createElement('tbody');
        tBody.className = "tablesorter-no-sort";
        tableRef.appendChild(tBody);
        var newRow = tBody.insertRow(-1);
        var data = info.overall.data;
        for(var index=0;index < data.length; index++){
            var cell = newRow.insertCell(-1);
            cell.innerHTML = formatter ? formatter(index, data[index]): data[index];
        }
    }

    // Create regular body
    tBody = document.createElement('tbody');
    tableRef.appendChild(tBody);

    var regexp;
    if(seriesFilter) {
        regexp = new RegExp(seriesFilter, 'i');
    }
    // Populate body with data.items array
    for(var index=0; index < info.items.length; index++){
        var item = info.items[index];
        if((!regexp || filtersOnlySampleSeries && !info.supportsControllersDiscrimination || regexp.test(item.data[seriesIndex]))
                &&
                (!showControllersOnly || !info.supportsControllersDiscrimination || item.isController)){
            if(item.data.length > 0) {
                var newRow = tBody.insertRow(-1);
                for(var col=0; col < item.data.length; col++){
                    var cell = newRow.insertCell(-1);
                    cell.innerHTML = formatter ? formatter(col, item.data[col]) : item.data[col];
                }
            }
        }
    }

    // Add support of columns sort
    table.tablesorter({sortList : defaultSorts});
}

$(document).ready(function() {

    // Customize table sorter default options
    $.extend( $.tablesorter.defaults, {
        theme: 'blue',
        cssInfoBlock: "tablesorter-no-sort",
        widthFixed: true,
        widgets: ['zebra']
    });

    var data = {"OkPercent": 99.45528511342481, "KoPercent": 0.5447148865751913};
    var dataset = [
        {
            "label" : "KO",
            "data" : data.KoPercent,
            "color" : "#FF6347"
        },
        {
            "label" : "OK",
            "data" : data.OkPercent,
            "color" : "#9ACD32"
        }];
    $.plot($("#flot-requests-summary"), dataset, {
        series : {
            pie : {
                show : true,
                radius : 1,
                label : {
                    show : true,
                    radius : 3 / 4,
                    formatter : function(label, series) {
                        return '<div style="font-size:8pt;text-align:center;padding:2px;color:white;">'
                            + label
                            + '<br/>'
                            + Math.round10(series.percent, -2)
                            + '%</div>';
                    },
                    background : {
                        opacity : 0.5,
                        color : '#000'
                    }
                }
            }
        },
        legend : {
            show : true
        }
    });

    // Creates APDEX table
    createTable($("#apdexTable"), {"supportsControllersDiscrimination": true, "overall": {"data": [0.9920670783752573, 500, 1500, "Total"], "isController": false}, "titles": ["Apdex", "T (Toleration threshold)", "F (Frustration threshold)", "Label"], "items": [{"data": [1.0, 500, 1500, "Comment"], "isController": false}, {"data": [1.0, 500, 1500, "go_To_site-54"], "isController": false}, {"data": [0.9560867148415787, 500, 1500, "Comments"], "isController": true}, {"data": [1.0, 500, 1500, "Guest"], "isController": true}, {"data": [1.0, 500, 1500, "go_To_site-86"], "isController": false}, {"data": [1.0, 500, 1500, "go_To_Site"], "isController": true}, {"data": [1.0, 500, 1500, "go_To_site-82"], "isController": false}, {"data": [1.0, 500, 1500, "go_To_Site-185"], "isController": false}, {"data": [1.0, 500, 1500, "Guest_book"], "isController": false}, {"data": [1.0, 500, 1500, "JDBC Request"], "isController": false}, {"data": [1.0, 500, 1500, "Debug Sampler"], "isController": false}, {"data": [1.0, 500, 1500, "Customers"], "isController": false}, {"data": [1.0, 500, 1500, "go_To_site"], "isController": true}, {"data": [0.9560867148415787, 500, 1500, "OK"], "isController": false}, {"data": [1.0, 500, 1500, "Main"], "isController": false}, {"data": [1.0, 500, 1500, "go_To_site-1"], "isController": false}, {"data": [1.0, 500, 1500, "go_To_Site-255"], "isController": false}]}, function(index, item){
        switch(index){
            case 0:
                item = item.toFixed(3);
                break;
            case 1:
            case 2:
                item = formatDuration(item);
                break;
        }
        return item;
    }, [[0, 0]], 3);

    // Create statistics table
    createTable($("#statisticsTable"), {"supportsControllersDiscrimination": true, "overall": {"data": ["Total", 14503, 79, 0.5447148865751913, 4.242846307660489, 0, 195, 3.0, 6.0, 8.0, 30.0, 48.216203277358694, 306.1602152480875, 18.357258834830496], "isController": false}, "titles": ["Label", "#Samples", "KO", "Error %", "Average", "Min", "Max", "Median", "90th pct", "95th pct", "99th pct", "Transactions\/s", "Received", "Sent"], "items": [{"data": ["Comment", 1799, 0, 0.0, 3.52918287937743, 1, 95, 3.0, 5.0, 6.0, 16.0, 5.98358256612208, 27.22939718690131, 1.741316020219121], "isController": false}, {"data": ["go_To_site-54", 1799, 0, 0.0, 3.7431906614785984, 2, 18, 3.0, 6.0, 8.0, 11.0, 5.982607538950134, 35.843063722128, 2.2902169485043484], "isController": false}, {"data": ["Comments", 1799, 79, 4.391328515842135, 11.588104502501398, 4, 119, 9.0, 16.0, 23.0, 65.0, 5.9827070169604255, 105.10903919500333, 7.379788955977719], "isController": true}, {"data": ["Guest", 1799, 0, 0.0, 17.95997776542525, 7, 224, 13.0, 29.0, 46.0, 101.0, 5.9822295526795335, 122.62290469209309, 8.622823066166983], "isController": true}, {"data": ["go_To_site-86", 1799, 0, 0.0, 6.757087270705948, 1, 195, 3.0, 8.0, 34.0, 84.0, 5.982746809090849, 26.9169857766347, 1.7410728018643291], "isController": false}, {"data": ["go_To_Site", 16, 0, 0.0, 52.8125, 15, 266, 33.0, 169.4000000000001, 266.0, 266.0, 0.06127122473519343, 2.8254022599508297, 0.06629737988925226], "isController": true}, {"data": ["go_To_site-82", 1799, 0, 0.0, 3.603668704836021, 2, 32, 3.0, 6.0, 7.0, 10.0, 5.982687121093711, 24.02422797064193, 2.301932349327072], "isController": false}, {"data": ["go_To_Site-185", 16, 0, 0.0, 10.4375, 2, 51, 7.5, 26.500000000000025, 51.0, 51.0, 0.05694031231761306, 1.2582474483622543, 0.023243213426525647], "isController": false}, {"data": ["Guest_book", 16, 0, 0.0, 12.8125, 3, 69, 8.0, 42.40000000000003, 69.0, 69.0, 0.05695186499560403, 0.38847818165153286, 0.016573882586611327], "isController": false}, {"data": ["JDBC Request", 47, 0, 0.0, 8.510638297872337, 0, 181, 3.0, 13.600000000000009, 28.799999999999898, 181.0, 0.1672972944112025, 0.440889967101165, 0.0], "isController": false}, {"data": ["Debug Sampler", 16, 0, 0.0, 0.5000000000000001, 0, 2, 0.0, 2.0, 2.0, 2.0, 0.05699264082525344, 0.30988009171362624, 0.0], "isController": false}, {"data": ["Customers", 1799, 0, 0.0, 3.8554752640355723, 2, 38, 3.0, 6.0, 8.0, 12.0, 5.9824682752933045, 35.846486837904706, 2.290163636635718], "isController": false}, {"data": ["go_To_site", 1800, 0, 0.0, 4.185555555555559, 0, 51, 3.0, 7.0, 9.0, 13.0, 5.982252650470272, 76.00947267896906, 2.3004864215327863], "isController": true}, {"data": ["OK", 1799, 79, 4.391328515842135, 4.546970539188431, 1, 112, 3.0, 6.0, 11.0, 41.0, 5.982925880228408, 1.8261932127131353, 3.336909798205122], "isController": false}, {"data": ["Main", 1799, 0, 0.0, 3.5119510839355232, 2, 15, 3.0, 5.0, 6.0, 9.0, 5.983662174208054, 76.0696427576567, 2.302307516248021], "isController": false}, {"data": ["go_To_site-1", 1799, 0, 0.0, 4.18732629238466, 2, 51, 3.0, 7.0, 9.0, 13.0, 5.981453835744424, 76.04156839230558, 2.3014578235188505], "isController": false}, {"data": ["go_To_Site-255", 16, 0, 0.0, 4.062500000000001, 2, 12, 3.0, 8.500000000000004, 12.0, 12.0, 0.056951256843049455, 0.22869489076037047, 0.02180165301022987], "isController": false}]}, function(index, item){
        switch(index){
            // Errors pct
            case 3:
                item = item.toFixed(2) + '%';
                break;
            // Mean
            case 4:
            // Mean
            case 7:
            // Median
            case 8:
            // Percentile 1
            case 9:
            // Percentile 2
            case 10:
            // Percentile 3
            case 11:
            // Throughput
            case 12:
            // Kbytes/s
            case 13:
            // Sent Kbytes/s
                item = item.toFixed(2);
                break;
        }
        return item;
    }, [[0, 0]], 0, summaryTableHeader);

    // Create error table
    createTable($("#errorsTable"), {"supportsControllersDiscrimination": false, "titles": ["Type of error", "Number of errors", "% in errors", "% in all samples"], "items": [{"data": ["500", 79, 100.0, 0.5447148865751913], "isController": false}]}, function(index, item){
        switch(index){
            case 2:
            case 3:
                item = item.toFixed(2) + '%';
                break;
        }
        return item;
    }, [[1, 1]]);

        // Create top5 errors by sampler
    createTable($("#top5ErrorsBySamplerTable"), {"supportsControllersDiscrimination": false, "overall": {"data": ["Total", 14503, 79, "500", 79, null, null, null, null, null, null, null, null], "isController": false}, "titles": ["Sample", "#Samples", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors"], "items": [{"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": ["OK", 1799, 79, "500", 79, null, null, null, null, null, null, null, null], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}]}, function(index, item){
        return item;
    }, [[0, 0]], 0);

});
