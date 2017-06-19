//
//  ViewController.swift
//  abc
//
//  Created by Advaya Gupta on 09/06/17.
//  Copyright © 2017 Advaya Gupta. All rights reserved.
//

import UIKit

class tableCell: UITableViewCell {
    @IBOutlet var numLabel: UILabel!
    var isExpanded = false
    
}

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    @IBOutlet var tableView: UITableView!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        self.navigationController?.navigationBar.barTintColor = UIColor.white
        
        for fontName in UIFont.fontNames(forFamilyName: "Avenir Next") {
            print(fontName)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 5
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cellOpt = tableView.dequeueReusableCell(withIdentifier: "reuseCell", for: indexPath) as? tableCell
        if cellOpt == nil {
            cellOpt = tableCell(style: UITableViewCellStyle.default, reuseIdentifier: "reuseCell")
        }
        guard let cell = cellOpt else {return UITableViewCell()}
        
        cell.numLabel?.text = "\(indexPath.row + 1)"
        
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let cellOpt = tableView.cellForRow(at: indexPath) as? tableCell
        guard let cell = cellOpt else {
            tableView.cellForRow(at: indexPath)?.isSelected = false
            return
        }
        showOrHideCell(cell: cell, indexPath: indexPath)
        
    }
    func showOrHideCell(cell: tableCell, indexPath: IndexPath) {
        if cell.isExpanded {
            hideCell(indexPath: indexPath)
        } else {
            showCell(indexPath: indexPath)
        }
    }
    func hideCell(indexPath: IndexPath) {
        var index = indexPath
        index.row += 1
        tableView.deleteRows(at: [index], with: UITableViewRowAnimation.automatic)
    }
    func showCell(indexPath: IndexPath) {
        var index = indexPath
        index.row += 1
        tableView.insertRows(at: [index], with: UITableViewRowAnimation.automatic)
    }

    @IBAction func onChange(_ sender: Any) {
        self.navigationController?.navigationBar.titleTextAttributes = [NSFontAttributeName: UIFont(name: "AvenirNext-DemiBold", size: 17)!]
    }

}

